//#pragma GCC optimize ("Ofast")
//#pragma GCC target ("avx2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define all(var) var.begin(),var.end()
const int MXVAL = 2e6+7;
int vis[MXVAL];
const int N = 2e5+7;
pair<int,int> A[N],B[N];
int ans[N];
vector<pair<pair<int,int>,int> > V[MXVAL];
void solve(){
    int n;
    cin>>n;
    vector<int> su;
    for(int i = 1;i<=n;++i){
        int a,b,m;
        cin>>a>>b>>m;
        su.push_back({a+b-m});
        int l = max(0,a-m),r = a-(m-(b-max(0,b-m)));
        V[a+b-m].push_back({{l,r},i});
        A[i] = {a,m};
        B[i] = {l,r};
    }
    int res = 0;
    for(int sum:su){
        if (vis[sum])
            continue;
        vis[sum] = 1;
        set<pair<int,int> > L,R;
        for(auto [bnd,ind]:V[sum]){
            L.insert({bnd.first,ind});
            R.insert({bnd.second,ind});
        }
        while(!L.empty()){
            ++res;
            int r = R.begin()->first;
            while(!L.empty() && L.begin()->first<=r){
                int pos = L.begin()->second;
                ans[pos] = r;
                L.erase(L.begin());
                R.erase({B[pos].second,pos});
            }
        }
    }
    cout<<res<<endl;
    for(int i = 1;i<=n;++i){
        cout<<A[i].first-ans[i]<<' '<<A[i].second-A[i].first+ans[i]<<endl;
    }
    for(int sum:su){
        vis[sum] = 0;
        V[sum].clear();
    }
}

signed main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin>>t;
    while (t--)
        solve();

    return 0;
}