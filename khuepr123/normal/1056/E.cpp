#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 1000005;
const ll oo = 1e18 + 7;
int n, m;
int x, y, z, k;
string s, t;
int p = 1000003;
int pre[maxN];
int pw[maxN];


int encode(int l1, int r1){
    --l1;
    int res = (pre[r1] - pre[l1] * pw[r1 - l1]) % mod;
    if(res < 0) res += mod; return res;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s >> t;
    pre[0] = 0;
    pw[0] = 1;
    n = t.size(); m = s.size();
    int c0 = 0;
    int c1 = 0;
    for(char c : s){
        if(c == '0') c0++; else c1++;
    }
    t = '0' + t;
    for1(i, 1, n){
        pre[i] = (pre[i - 1] * p + t[i]) % mod;
        pw[i] = (pw[i - 1] * p) % mod;
    }
    int ans = 0;
    for1(i, 1, n - 1){
        int j = (n - (i * c1)) / c0;
        if(j <= 0) continue;
        if((j * c0 + i * c1) == n){
            bool killed = 0;
            int cur = 1;
            int res1 = -1;
            int res0 = -1;
            for(char c : s){
                if(c == '0'){
                    x = encode(cur, cur + j - 1);
                    cur += j;
                    if(res0 == -1) res0 = x;
                    else if(x != res0) killed = 1;
                }
                else{
                    x = encode(cur, cur + i - 1);
                    cur += i;
                    if(res1 == -1) res1 = x;
                    else if(x != res1) killed = 1;
                }
            }
            if(res0 == res1) killed = 1;
            if(!killed) ++ans;
        }
    }
    cout << ans << endl;
}