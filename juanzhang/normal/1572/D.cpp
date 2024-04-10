#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
//mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}
inline int read(){
  #define nc getchar()
  int x=0;char c=nc;bool f=0;
  while(c<48)f|=c=='-',c=nc;
  while(c>47)x=x*10+(c^48),c=nc;
  return f?-x:x;
  #undef nc
}

typedef double db;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;

const int maxV=1<<20|114;

int k;

int dist[maxV], pre[maxV], head[maxV], inq[maxV];
queue<int> Q;
struct edge { int to, cap, cost, nxt; } e[1000000];

int cnt=0;

void addline(int u, int v, int cap, int cost) {
    e[cnt] = (edge){v, cap, cost, head[u]}, head[u] = cnt++;
    e[cnt] = (edge){u, 0, -cost, head[v]}, head[v] = cnt++;
}

bool spfa(int s, int t) {
    fill(dist, dist + t + 1, INT_MIN);
    Q.push(s), dist[s] = 0;
    while (!Q.empty()) {
        int v = Q.front(); Q.pop(), inq[v] = 0;
        for (int i = head[v]; ~i; i = e[i].nxt) {
            if (e[i].cap && dist[e[i].to] < dist[v] + e[i].cost) {
                dist[e[i].to] = dist[v] + e[i].cost, pre[e[i].to] = i;
                if (!inq[e[i].to]) Q.push(e[i].to), inq[e[i].to] = 1;
            }
        }
    }
    return dist[t] > INT_MIN;
}

int upd(int s, int t) {
    for (int i = t; i ^ s; i = e[pre[i] ^ 1].to) {
        e[pre[i]].cap--, e[pre[i] ^ 1].cap++;
    }
    return dist[t];
}

int n,A[1<<20|114];bool vis[1<<20|114];

  vector<array<int,3>>vec;
void solve(){
  cin>>n>>k;
  rep(i,0,(1<<n)-1){
    A[i]=read();
  }
  memset(head,-1,sizeof head);
  int S=(1<<n),T=S+1;
  rep(i,0,(1<<n)-1){
    if(__builtin_parity(i)){
      rep(j,0,n-1)vec.push_back({A[i]+A[i^(1<<j)],i,i^(1<<j)});
    }
  }
  int pos=min((int)vec.size(),n*k*2);
  
  nth_element(vec.begin(),vec.begin()+pos,vec.end(),greater<array<int,3>>());
  rep(_,0,pos-1){
    addline(vec[_][1],vec[_][2],1,0);
    vis[vec[_][1]]=vis[vec[_][2]]=1;
  }
  rep(i,0,(1<<n)-1)if(vis[i]){
    if(__builtin_parity(i)){
      addline(S,i,1,A[i]);
    }else{
      addline(i,T,1,A[i]);
    }
  }
  int res=0;
  while(spfa(S,T)&&k--)res+=upd(S,T);
  cout<<res<<endl;
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}