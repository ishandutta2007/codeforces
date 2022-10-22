#include<bits/stdc++.h>
using namespace std;

#define sadasdads long long
#define pb push_back
#define fi first
#define se second
#define fir fi.fi
#define sec fi.se
#define endl "\n"
#define PI 3.141592653589793238462643383279502884
#define ll long long
const ll mod = 1e9 + 7;
const int maxN = 600005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int ans[maxN];
bool day1[maxN];
char c;
set<int> st[maxN];
set<int> vc;
set<int> newset;

void process(int node){
    vc.insert(node);
    for(auto itr = st[node].begin(); itr != st[node].end(); ++itr){
        if(vc.find(*itr) != vc.end()) continue;
        vc.insert(*itr);
        process(*itr);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> n;
        for(int i = 0; i <= n * 2 + 3; i++){
            st[i].clear();
            st[i].insert(i);
            vc.clear();
            ans[i] = -1;
        }
        for(int i = 1; i <= n; i++){
            cin >> c;
            day1[i] = (c != 'R');
            // L 0 R 1
        }
        n++;
        for(int i = 1; i < n; i++){
            if(day1[i]) st[i + 1].insert(i + n);
            else        st[i].insert(i + 1 + n);
            if(day1[i]) st[i + n].insert(i + 1);
            else        st[i + 1 + n].insert(i);
        }
        for(int i = 1; i <= n; i++){
            vc.clear();
            if(ans[i] + 1) continue;
            process(i);
            newset.clear();
            if(st[i].size() == 0){
                ans[i] = 1; continue;
            }
            for(auto itr = vc.begin(); itr != vc.end(); ++itr){
                int node = *itr;
                for(auto itt = st[node].begin(); itt != st[node].end(); ++itt){
                    newset.insert(*itt);
                }
            }
            for(auto itr = vc.begin(); itr != vc.end(); ++itr){
                ans[*itr] = newset.size();
            }
            
        }
        for(int i = 1; i <= n; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}