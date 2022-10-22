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
const int maxN = 600005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;
int m;

map<int, int> mp;

int b[maxN];
bool iss[maxN];
vector<int> ass;

void exec(int sf){
    for1(i, 1, n){
        b[i] = a[i + sf];
        iss[i] = 0;
    }
    int fs = 0;
    for1(i, 1, n){
        if(iss[i]) continue;
        int cur = b[i];
        iss[i] = 1;
        iss[cur] = 1;
        while(cur != i){
            cur = b[cur];
            iss[cur] = 1;
            ++fs;
        }
    }
    if(fs <= m) ass.pb(sf);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    // cout << endl << endl << endl << endl;
    while(o--){
        mp.clear();
        ass.clear();
        cin >> n >> m;
        int cnv = n - (n / 3) * 2;
        for1(i, 1, n){
            cin >> a[i];
        }
        for1(i, n + 1, n * 2){
            a[i] = a[i - n];
        }
        for1(i, 1, n * 2){
            mp[i - a[i]]++;
        }
        for(ii child : mp){
            if(child.se < cnv) continue;
            if(child.fi < 0 || child.fi >= n) continue;
            // cout << child.fi << " " << child.se << endl;
            exec(child.fi);
        }
        cout << ass.size() << " ";
        for(int child : ass) cout << child << " ";
        cout << endl;
    }
}