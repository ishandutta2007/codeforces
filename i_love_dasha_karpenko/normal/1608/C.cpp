#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define all(var) var.begin(), var.end()
#define mp make_pair
#define gp(x,y) ((x-1)*m+y-1)
const int N = 1e5+7;
int vis[N];
pair<int,int> param[N];
set<pair<int,int> > A,B;
void del(int pos){
    A.erase({param[pos].first,pos});
    B.erase({param[pos].second,pos});
    vis[pos] = 1;
    auto it1 = A.upper_bound({param[pos].first,pos});
    if (it1!=A.end())
        del(it1->second);
    auto it2 = B.upper_bound({param[pos].second,pos});
    if (it2!=B.end())
        del(it2->second);
}
void solve(){
    int n;
    cin>>n;

    for(int i = 1;i<=n;++i) {
        int val;
        cin>>val;
        A.insert({val,i});
        param[i].first = val;
    }
    for(int i = 1;i<=n;++i) {
        int val;
        cin>>val;
        B.insert({val,i});
        param[i].second = val;
    }
    del(B.rbegin()->second);
    A.clear();
    B.clear();
    for(int i = 1;i<=n;++i)
        cout<<vis[i],vis[i] = 0;
    cout<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin>>t;
    while(t--)
        solve();
}