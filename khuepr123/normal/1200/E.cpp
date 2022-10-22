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
const ll mdd = 1e9 + 9;
 
const int maxN = 1000005;
const ll oo = 1e18 + 7;
int n; string a[maxN];
int x, y, z, k;
int p1[maxN];
int p2[maxN];
 
void fun(string &s, string &t){
    map<ii, int> mp;
    int rs1 = 0;
    int rs2 = 0;
    int gg = 0;
    for1(i, 0, t.size() - 1){
        char c = t[i];
        if(c >= 'a') c = c - 'a' + 'Z' + 1;
        c = c - 'A' + 1;
        if(c < 0) c += 80;
        rs1 = ((rs1 * 1000003) + c) % mod;
        rs2 = ((rs2 * 1000033) + c) % mdd;
        mp[ii(rs1, rs2)] = ++gg;
    }
    rs1 = 0;
    rs2 = 0;
    int mx = 0;
    for2(i, s.size() - 1, 0){
        int u = s.size();
        u = u - t.size();
        if(i < u) break;
        char c = s[i];
        if(c >= 'a') c = c - 'a' + 'Z' + 1;
        c = c - 'A' + 1;
        if(c < 0) c += 80;
        rs1 = (rs1 + c * p1[s.size() - 1 - i]) % mod;
        rs2 = (rs2 + c * p2[s.size() - 1 - i]) % mdd;
        if(mp.find(ii(rs1, rs2)) != mp.end()){
            mx = max(mx, mp[ii(rs1, rs2)]);
        }
    }
    for1(i, mx, t.size() - 1){
        s += t[i];
    }
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int ans = 0;
    p1[0] = 1;
    p2[0] = 1;
    for1(i, 1, maxN - 1){
        p1[i] = (p1[i - 1] * 1000003) % mod;
        p2[i] = (p2[i - 1] * 1000033) % mdd;
    }
    
    for1(i, 1, n){
        cin >> a[i];
        ans += a[i].size();
    }
    string s = a[1];
    for1(i, 2, n){
        fun(s, a[i]);
    }
    cout << s;
}