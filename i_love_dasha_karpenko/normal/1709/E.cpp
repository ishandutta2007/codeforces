//#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
//#define int ll
const int N = 2e5+7;
int A[N],sz[N],B[N];
vector<int> G[N];
void calc(int v,int par){
    sz[v] = 1;
    if (par!=v) {
        A[v] ^= A[par];
    }
    for(int to:G[v]){
        if (to==par){
            continue;
        }
        calc(to,v);
        sz[v] += sz[to];
    }
}
int cnt = 0;
void dfs(int v,int par,set<int> &S){
    int big = -1;
    for(int to:G[v]){
        if (to==par){
            continue;
        }
        if (big==-1 || sz[to]>sz[big]){
            big = to;
        }
    }
    bool flag = 0;
    if (big!=-1){
        dfs(big,v,S);
        for(int to:G[v]){
            if (to==par || to==big){
                continue;
            }
            set<int> ns;
            dfs(to,v,ns);
            for(int to:ns){
                if (S.count(B[v]^to)){
                    flag = 1;
                }
            }
            for(int to:ns){
                S.insert(to);
            }
        }
    }
    if (S.count(B[v]^A[v])){
        flag = 1;
    }
    S.insert(A[v]);
    if (flag){
        cnt += 1;
        S.clear();
    }
}
void solve(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i+=1){
        cin>>A[i];
        B[i] = A[i];
    }
    for(int i = 1;i<n;i+=1){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    calc(1,1);
    set<int> S;
    dfs(1,1,S);
    cout<<cnt<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
  //  cin>>t;
    while(t--){
        solve();
    }
    return 0;
}