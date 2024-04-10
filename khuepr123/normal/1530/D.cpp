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

bool asd[maxN];

bool killed;
void solve(){
    if(killed) return;
    set<int> st;
    vector<int> vc;
    for1(i, 1, n){
        if(asd[i] == 0){
            vc.pb(i);
        }
        else st.insert(a[i]);
    }
    for1(i, 1, n){
        if(st.find(i) == st.end()) st.insert(i);
        else st.erase(i);
    }
    for1(i, 1, n){
        if(asd[i] == 0){
            if(st.find(i) != st.end()){
                a[i] = i;
                st.erase(i);
            }
        }
    }
    for1(i, 1, n){
        if(asd[i] == 0){
            if(a[i] != i){
                a[i] = *st.begin();
                st.erase(st.begin());
            }
        }
    }
    for1(i, 0, vc.size() - 1){
        if(i == vc.size() - 1) return;
        int id = i + 1;
        // cout << i << " " << id << endl;
        swap(a[vc[i]], a[vc[id]]);
    }
    killed = 1;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        killed = 0;
        int cn = 0;
        cin >> n;
        for1(i, 1, n){
            cin >> a[i];
            asd[i] = 0;
        }
        set<int> st;
        map<int, int> mp;
        for1(i, 1, n){
            if(st.find(a[i]) == st.end()){
                asd[i] = 1;
                ++cn;
                mp[a[i]]++;
                mp[i]++;
            }
            st.insert(a[i]);
        }
        for(auto child : mp){
            if(child.se == 1){
                solve();
                break;
            }
        }
        if(!killed)
        for1(i, 1, n){
            if(asd[i] == 0){
                x = a[i];
                asd[i] = 1;
                for1(j, 1, n){
                    if(a[j] == x){
                        asd[j] = 0;
                        solve();
                        break;
                    }
                }
                break;
            }
        }
        cout << cn << endl;
        for1(i, 1, n) cout << a[i] << " ";
        cout << endl;
    }
}