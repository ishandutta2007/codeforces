#include <stdio.h>
#include <vector>
#include <utility>
#define MAXL 55

using namespace std;

const int adj[4][2]={1,0, 0,1, -1,0, 0,-1};

int rn,cn;
char gr[MAXL][MAXL];

typedef pair<int,int> pii;
vector<pii> que[2];
int visited[MAXL][MAXL]={0},visid=0;

inline void relax(int &x,int val) { if(val<x) x=val; }
inline bool valid(int r,int c) { return r>=0&&r<rn&&c>=0&&c<cn; }

inline int color(int sr,int sc) {
   int cq,ci,ni;
   ++visid;
   que[0].clear();
   que[0].push_back(make_pair(sr,sc));
   visited[sr][sc]=visid;
   for(cq=0;!que[cq&1].empty();cq++) {
      ci=cq&1;
      ni=!ci;
      que[ni].clear();
      while(!que[ci].empty()) {
         int r=que[ci].back().first;
         int c=que[ci].back().second;
         que[ci].pop_back();
         for(int i=0;i<4;i++) {
            int nr=r+adj[i][0];
            int nc=c+adj[i][1];
            if(!valid(nr,nc)) continue;
            if(visited[nr][nc]==visid) continue;
            visited[nr][nc]=visid;
            if(gr[nr][nc]==gr[r][c]) que[ci].push_back(make_pair(nr,nc));
            else que[ni].push_back(make_pair(nr,nc));
         }
      }
   }
   return cq-((gr[sr][sc]=='B')^(cq&1));
}

inline int solve() {
   int opt=rn*cn;
   for(int i=0;i<rn;i++)
      for(int j=0;j<cn;j++)
         relax(opt,color(i,j));
   return opt;
}

int main(void)
{
   while(scanf("%d %d",&rn,&cn)==2) {
      for(int i=0;i<rn;i++)
         scanf("%s",gr[i]);
      printf("%d\n",solve());
   }
   return 0;
}