/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define eb emplace_back
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

string s;
int ans;
void back(int pos){
    if(pos == 11){
        int c2[] = {0, 0};
        int nmp[] = {0, 0};
        for1(i, 1, 10){
            c2[i & 1] += a[i];
            nmp[i & 1]++;
            for1(j, 0, 1){
                if(c2[j] + (5 - nmp[j]) < c2[j ^ 1]){
                    ans = min(ans, i);
                    return;
                }
            }
        }
        return;
    }
    bool f[2] = {1, 1};
    if(s[pos] == '1') f[0] = 0;
    if(s[pos] == '0') f[1] = 0;
    for1(i, 0, 1){
        if(f[i]){
            a[pos] = i;
            back(pos + 1);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> s; s = '?' + s;
        ans = 10;
        back(1);
        cout << ans << endl;
    }
}