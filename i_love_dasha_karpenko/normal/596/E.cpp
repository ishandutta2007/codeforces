//#pragma GCC optimize ("Ofast")
//#pragma GCC target ("avx2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define all(var) var.begin(),var.end()
#define gi(x) int(x-'0')
#define mp make_pair
const pair<int,int> operator + (const pair<int,int> a,const pair<int,int> b){
    return {a.first+b.first,a.second+b.second};
}
const int N = 2e2+7;
int A[N][N];
const int MAXN = 10;
pair<int,int> vec[MAXN];
int n,m,q,vis[N][N],col[N][N];
inline int check(const pair<int,int> a){
    return a.first>=1 && a.first<=n && a.second>=1 && a.second<=m;
}
int cyc = 0;
int aval[N*N][MAXN];
int dfs(int x,int y){
    if (vis[x][y]==1) {
        ++cyc;
        return x*1000+y;
    }
    if (vis[x][y]==2)
        return 0;
    vis[x][y] = 1;
    pair<int,int> nxt = mp(x,y)+vec[A[x][y]];
    if (check(nxt)){
        int ret = dfs(nxt.first,nxt.second);
        if (ret) {
            col[x][y] = cyc;
            aval[cyc][A[x][y]] = 1;
        }
        if (ret==x*1000+y)
            ret = 0;
        vis[x][y] = 2;
        return ret;
    }
    else{
        ++cyc;
        col[x][y] = cyc;
        aval[cyc][A[x][y]] = 1;
        vis[x][y] = 2;
        return 0;
    }
}
int depth[N][N];
void calc(int x,int y){
    if (col[x][y] || vis[x][y])
        return;
    vis[x][y] = 1;
    pair<int,int> nxt = vec[A[x][y]]+mp(x,y);
    calc(nxt.first,nxt.second);
    depth[x][y] = depth[nxt.first][nxt.second]+1;
}
bool mc(const pair<int,int> a,const pair<int,int> b){
    return depth[a.first][a.second]<depth[b.first][b.second];
}
int dp[N][N],cdp[N*N];
void solve(){

    cin>>n>>m>>q;
    for(int i = 1;i<=n;++i)
        for(int j = 1;j<=m;++j){
            char ch;
            cin>>ch;
            A[i][j] = gi(ch);
        }
    for(int num = 0;num<MAXN;++num)
        cin>>vec[num].first>>vec[num].second;
    for(int i = 1;i<=n;++i)
        for(int j = 1;j<=m;++j){
            if (!vis[i][j])
                dfs(i,j);
        }
    memset(vis,0,sizeof(vis));
    vector<pair<int,int> > V;
    for(int i = 1;i<=n;++i)
        for(int j = 1;j<=m;++j){
            if (!col[i][j]){
                if (!vis[i][j])
                    calc(i,j);
                V.push_back(mp(i,j));
            }
        }
    sort(all(V),mc);

    while(q--){

        string s;
        cin>>s;
        reverse(all(s));
        int sz = s.size();
        int flag = 0;
        for(int c = 1;c<=cyc;++c){
            int ptr = 0;
            while(ptr<sz && aval[c][gi(s[ptr])])
                ++ptr;
            cdp[c] = ptr;
            if (ptr==sz)
                flag = 1;
        }
        for(auto [x,y]:V){

            pair<int,int> nxt = vec[A[x][y]]+mp(x,y);
            dp[x][y] = dp[nxt.first][nxt.second];
            if (col[nxt.first][nxt.second])
                dp[x][y] = cdp[col[nxt.first][nxt.second]];
            if (dp[x][y]<sz && gi(s[dp[x][y]])==A[x][y])
                ++dp[x][y];
            if (dp[x][y]==sz)
                flag = 1;
        }
        if (flag)
            cout<<"YES\n";
        else cout<<"NO\n";
    }
}

signed main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin>>t;
    while (t--)
        solve();

    return 0;
}