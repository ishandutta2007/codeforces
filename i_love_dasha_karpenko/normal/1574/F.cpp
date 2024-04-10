#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define in_place dfgdsgs
#define fpos sdfdsf
const ll MOD = 998244353;
const ll N = 6e5+7;
deque<int> A[N];
map<int,int> S[N];
vector<int> V[N];
bool dbl[N],del[N],vis[N];
queue<int> Q;
int fpos[N];
void bfs(int start){

    Q.push(start);
    while(!Q.empty()){
        int s = Q.front();
        Q.pop();
        vis[s] = 1;
        for(auto v:V[s]){
            if (del[v])
                continue;
            del[v] = 1;
            for(int to:A[v]){
                if (vis[to])
                    continue;
                vis[to] = 1;
                Q.push(to);
            }
            A[v].clear();
        }
    }
}
int in_place[N];
bool act[N];
ll dp[N];
int n,m,k;
int get(int v,int s){
    return S[v][s]-fpos[v];
}
void solve(int s){
    if (vis[s])
        return;
    int flag = 0;
    int cnt = 0,big = 0,ps;
    for(auto v:V[s]){
        if (dbl[v]){
            flag = 1;
            break;
        }
        if (!del[v]){
            ++cnt;
            if (A[big].size()<A[v].size())
                big = v,ps = get(v,s);
        }
    }
    if (flag){
        bfs(s);
        return;
    }
    if (cnt<2)
        return;
    int shift = 0;
    for(auto v:V[s]){
        if (del[v])
            continue;
        shift = max(shift,get(v,s));
    }
    flag = 0;
    int mx = 0;
    int bsh = shift-ps,bsz = A[big].size();
    for(auto v:V[s]){
        if (del[v] || v==big)
            continue;
        int sz = A[v].size();
        int sh = shift-get(v,s);
        mx = max(mx,sz+sh);
        for(int i = 0;i<sz;++i){
            int rpos = i+sh;
            if (rpos-bsh>=0 && rpos-bsh<bsz){
                if (A[v][i]!=A[big][rpos-bsh]){
                    flag = 1;
                    break;
                }
            }
            else{
                if (in_place[i+sh]==0)
                    in_place[i+sh] = A[v][i];
                if (in_place[i+sh]!=A[v][i]){
                    flag = 1;
                    break;
                }
            }
        }
    }
    if (flag){
        bfs(s);
        for(int i = 0;i<mx;++i)
            in_place[i] = 0;
        return;
    }
    for(auto v:V[s]){
        if (v==big)
            continue;
        del[v] = 1;
        A[v].clear();
    }
    V[s].clear();
    flag = 0;
    for(int i = bsh-1;i>=0;--i){
        A[big].push_front(in_place[i]);
        if (S[big].count(in_place[i])==0){
            S[big][in_place[i]] = i-bsh+fpos[big];
            V[in_place[i]].push_back(big);
        }
        else{
            flag = 1;
        }
        in_place[i] = 0;
    }

    for(int i = bsh+bsz;i<mx;++i){
        A[big].push_back(in_place[i]);
        if (S[big].count(in_place[i])==0){
            S[big][in_place[i]] = i-bsh+fpos[big];
            V[in_place[i]].push_back(big);
        }
        else{
            flag = 1;
        }
        in_place[i] = 0;
    }
    fpos[big] -= bsh;
    ///
    if (flag) {
        dbl[big] = del[big] = 1;
        bfs(s);
    }
}
void solve(){

    cin>>n>>m>>k;
    for(int i = 1;i<=n;++i){
        int sz;
        cin>>sz;
        A[i].resize(sz);
        for(int j = 0;j<sz;++j){
            cin>>A[i][j];
            act[A[i][j]] = 1;
            if (S[i].count(A[i][j])==0){
                V[A[i][j]].push_back(i);
                S[i][A[i][j]] = j;
            }
            else dbl[i] = 1;
        }
    }
    for(int s = 1;s<=k;++s){
        solve(s);
    }
    map<int,int> bag;
    for(int i = 1;i<=n;++i){
        if (!del[i]){
            bag[A[i].size()]++;
        }
    }
    for(int s = 1;s<=k;++s){
        if (!act[s])
            bag[1]++;
    }
    dp[0] = 1;
    for(int i = 0;i<m;++i){
        for(auto to:bag){
            if (i+to.first>m)
                break;
            dp[i+to.first] = (dp[i+to.first]+dp[i]*to.second)%MOD;
        }
    }
    cout<<dp[m]<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}