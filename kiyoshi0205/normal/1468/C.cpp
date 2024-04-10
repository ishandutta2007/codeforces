#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define rep(i,n) for(int i=0; i<(n); i++)

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    set<pair<int,int>> se1,se2;
    int id = 1;
    vector<int> ans;
    while(t--){
        int a; cin >> a;
        if(a == 1){
            int m; cin >> m;
            se1.emplace(id,-m);
            se2.emplace(-m,id);
            id++;
        }
        if(a == 2){
            auto p = *se1.begin();
            ans.push_back(p.first);
            se1.erase(se1.begin());
            swap(p.first, p.second);
            se2.erase(p);
        }
        if(a == 3){
            auto p = *se2.begin();
            ans.push_back(p.second);
            se2.erase(se2.begin());
            swap(p.first, p.second);
            se1.erase(p);
        }
    }
    int sz = ans.size();
    rep(i,sz) cout << ans[i] << " \n"[i==sz-1];
}