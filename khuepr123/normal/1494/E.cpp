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
 
map<ii, int> mp;
 
int ct0, ct1;
 
signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    ct0 = 0;
    ct1 = 0;
    char c; int o; cin >> o >> o;
    while(o--){
        cin >> c >> x;
        if(c == '?'){
            if((x & 1) && ct1) cout << "YES\n";
            else if(((x & 1) == 0) && ct0) cout << "YES\n";
            else cout << "NO\n";
        }
        else{
            cin >> y;
            ii cl = ii(y, x);
            bool fl = (mp.find(cl) != mp.end());
            ii lc = ii(x, y);
            if(c == '+'){
                cin >> c;
                z = c - 'A';
                if(fl) ct1++;
                if(fl && mp[cl] == z) ct0++;
                mp[lc] = z;
            }
            else{
                if(fl) ct1--;
                if(fl && mp[cl] == mp[lc]) ct0--;
                mp.erase(lc);
            }
        }
    }
}