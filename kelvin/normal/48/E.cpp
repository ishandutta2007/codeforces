#include <stdio.h>
#include <string.h>
#include <vector>
#include <utility>
#define MAXN 205

using namespace std;

typedef pair<int,int> pii;

int ia,ib,thr;
int an,bn,mn;
pii agrow[MAXN],bgrow[MAXN];
pii move[MAXN*2][2];
vector<pii> adj[MAXN][MAXN];

int ql,qr;
pii que[MAXN*MAXN];
int visited[MAXN][MAXN]={0},visid=0;
int dist[MAXN][MAXN];
bool instack[MAXN][MAXN]={0};
int dp[MAXN][MAXN];

inline int max(int a,int b) { return a>b?a:b; }

inline void construct() {
   for(int a=0;a<=thr;a++) {
      for(int b=0;b<=thr;b++) {
         for(int i=0;i<mn;i++) {
            int ca=move[i][0].first;
            int cb=move[i][0].second;
            if(ca>a) continue;
            if(cb>b) continue;
            int na=a+move[i][1].first-ca;
            int nb=b+move[i][1].second-cb;
            if(na+nb>thr) continue;
            adj[a][b].push_back(make_pair(na,nb));
            //printf("%d %d -> %d %d\n",a,b,na,nb);
         }
      }
   }
}

inline int bfs() {
   ++visid;
   ql=qr=0;
   que[qr++]=make_pair(ia,ib);
   visited[ia][ib]=visid;
   dist[ia][ib]=0;
   while(ql<qr) {
      int a=que[ql].first;
      int b=que[ql++].second;
      if(!a&&!b) return dist[a][b];
      for(int i=0;i<adj[a][b].size();i++) {
         int na=adj[a][b][i].first;
         int nb=adj[a][b][i].second;
         if(visited[na][nb]==visid) continue;
         visited[na][nb]=visid;
         dist[na][nb]=dist[a][b]+1;
         que[qr++]=make_pair(na,nb);
      }
   }
   return -1;
}

bool dfscycle(int a,int b) {
   visited[a][b]=visid;
   instack[a][b]=1;
   for(int i=0;i<adj[a][b].size();i++) {
      int na=adj[a][b][i].first;
      int nb=adj[a][b][i].second;
      if(instack[na][nb]) return 1;
      if(visited[na][nb]==visid) continue;
      if(dfscycle(na,nb)) return 1;
   }
   instack[a][b]=0;
   return 0;
}

int get(int a,int b) {
   if(dp[a][b]<0) {
      dp[a][b]=0;
      for(int i=0;i<adj[a][b].size();i++) {
         int na=adj[a][b][i].first;
         int nb=adj[a][b][i].second;
         dp[a][b]=max(dp[a][b],get(na,nb)+1);
      }
   }
   return dp[a][b];
}

inline void solve() {
   construct();
   // if (ia,ib) can reach (0,0): win
   int d=bfs();
   if(d>=0) {
      puts("Ivan");
      printf("%d\n",d);
      return;
   }
   // if (ia,ib) on a cycle: draw
   ++visid;
   if(dfscycle(ia,ib)) {
      puts("Draw");
      return;
   }
   // lose otherwise
   puts("Zmey");
   memset(dp,-1,sizeof(dp));
   printf("%d\n",get(ia,ib)+1);
}

int main(void)
{
   scanf("%d %d %d",&ia,&ib,&thr);
   mn=0;
   scanf("%d",&an);
   for(int i=0;i<an;i++) {
      scanf("%d %d",&agrow[i].first,&agrow[i].second);
      move[mn][0]=make_pair(i+1,0);
      move[mn++][1]=agrow[i];
   }
   scanf("%d",&bn);
   for(int i=0;i<bn;i++) {
      scanf("%d %d",&bgrow[i].first,&bgrow[i].second);
      move[mn][0]=make_pair(0,i+1);
      move[mn++][1]=bgrow[i];
   }
   solve();
   return 0;
}