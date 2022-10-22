/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

#define all(flg) flg.begin(), flg.end()
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
int n;
int x, y, z, k;

vector<vector<int>> a;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        a.clear();
        vector<ii> sex;
        cin >> z >> n;
        bool killed = 0;
        while(z--){
            vector<int> kalm;
            for1(i, 1, n){
                cin >> x; kalm.pb(x);
            }
            vector<int> sus = kalm; sort(all(sus));
            vector<int> pin;
            for1(i, 0, n - 1){
                if(kalm[i] != sus[i]) pin.pb(i);
            }
            if(pin.size() > 2) killed = 1;
            else if(!pin.empty()) sex.pb({pin[0], pin[1]});
            a.pb(kalm);
        }
        sort(all(sex)); sex.resize(unique(all(sex)) - sex.begin());
        if(sex.empty()) sex.pb({0, 0});
        if(sex.size() > 1) killed = 1;
        ii pr = sex[0];
        for(auto &vc : a){
            swap(vc[pr.fi], vc[pr.se]);
        }
        for(auto &vc : a){
            vector<int> sus = vc;
            sort(all(sus));
            for1(i, 0, n - 1) if(sus[i] != vc[i]) killed = 1;
        }
        if(killed) cout << "-1\n";
        else cout << pr.fi + 1 << " " << pr.se + 1 << endl;
    }
}