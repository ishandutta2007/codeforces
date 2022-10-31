#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define int ll
const int N = 2e5+7;
vector<int> C[N];

const bool operator < (const vector<int> &a,const vector<int> &b){
    int sz = min(a.size(),b.size());
    for(int i = 0;i<sz;++i){
        if (a[i]!=b[i])
            return a[i]<b[i];
    }
    return a.size()<b.size();
}
typedef pair<ll,vector<int> > qnode;
void solve(){
    int n;
    cin>>n;
    qnode start;
    start.first = 0;
    for(int i = 0;i<n;++i){
        int k;
        cin>>k;
        start.second.push_back(k-1);
        C[i].resize(k);
        for(int j = 0;j<k;++j)
            cin>>C[i][j];
        start.first+=C[i][start.second[i]];
    }
    int m;
    cin>>m;
    set<vector<int> > B;
    for(int i = 1;i<=m;++i){
        vector<int> bld(n);
        for(int j = 0;j<n;++j){
            cin>>bld[j];
            --bld[j];
        }
        B.insert(bld);
    }
    set<qnode> S;
    S.insert(start);
    while(!S.empty()){
        vector<int> cur = S.rbegin()->second;
        ll sum = S.rbegin()->first;
        if (!B.count(cur)){
            for(int to:cur)
                cout<<to+1<<' ';
            cout<<endl;
            return;
        }
        S.erase(*S.rbegin());
        for(int i = 0;i<n;++i){
            if (cur[i]==0)
                continue;
            vector<int> fr = cur;
            fr[i]--;
            qnode fork = {sum-C[i][cur[i]]+C[i][fr[i]],fr};
            S.insert(fork);

        }
    }
    assert(0);


}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}