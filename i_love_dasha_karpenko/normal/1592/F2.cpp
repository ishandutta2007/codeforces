#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
#define all(var) var.begin(),var.end()
const int N = 500+7;
int A[N][N],T[N],cur[N][N];
void add(int pos){
    for(int i = pos;i<N;i+=i&-i)
        T[i]^=1;
}
int get(int pos){
    if (pos==0)
        return 0;
    int ret = 0;
    for(int i = pos;i>0;i-=i&-i)
        ret^=T[i];
    return ret;
}
int val(int pos){
    return get(N-1)^get(pos-1);
}
vector<int> G[N];
int P[N],vis[N];
int dfs(int v){
    if (vis[v])
        return 0;
    vis[v] = 1;
    for(int to:G[v]){
        if (P[to]==0){
            P[to] = v;
            vis[v] = 0;
            return 1;
        }
    }
   for(int to:G[v]){
        int par = P[to];
        if (dfs(par)){
            vis[v] = 0;
            P[to] = v;
            return 1;
        }
    }
    return 0;
}
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=m;++j){
            char ch;
            cin>>ch;
            if (ch=='W')
                A[i][j] = 0;
            else A[i][j] = 1;
        }
    }
    int res = 0;
    for(int i = n;i>=1;--i){
        int flag = 0,last = m;
        for(int j = m;j>=1;--j){
            if (A[i][j]==val(j)){
                if (flag){
                    add(last),cur[i][last] = 1;
                    ++res;
                    last = j;
                }
                else
                    flag = 0;
            }
            else{
                if (flag==0)
                    last = j;
                flag = 1;
            }
        }
        if (flag)
            add(last),++res,cur[i][last] = 1;
    }
    for(int i = 1;i<n;++i){
        for(int j = 1;j<m;++j){
            if (cur[i][j] && cur[i][m] && cur[n][j]){
                G[i].push_back(j);
            }
        }
    }
    int add = 0;
    for(int i = 1;i<=n;++i){
        add+=dfs(i);
    }
    add+=cur[n][m];
    cout<<res-add+(add&1)<<endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while(t--)
        solve();
}