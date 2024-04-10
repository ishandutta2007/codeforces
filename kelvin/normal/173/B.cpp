#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAXL 1050

using namespace std;

int dir[4][2] = {1,0, 0,1, -1,0, 0,-1};

#define H 0
#define V 1

class State {
   public:
      int r,c,d;
      State(int _r,int _c,int _d):r(_r),c(_c),d(_d) {}
      const bool operator==(const State &b) const {
         return r==b.r&&c==b.c&&d==b.d;
      }
};

typedef pair<int,int> pii;

const int inf=1000000000;

int rn,cn;
char gr[MAXL][MAXL];
int dist[MAXL][MAXL][2];
vector<State> que[2];

inline bool valid(int r,int c) {
   return r>=0&&r<rn&&c>=0&&c<cn;
}

inline int solve() {
   for(int i=0;i<rn;i++)
      for(int j=0;j<cn;j++)
         dist[i][j][H]=dist[i][j][V]=inf;
   que[0].push_back(State(rn-1,cn-1,H));
   dist[rn-1][cn-1][H]=0;
   for(int t=0;;t++) {
      int tt=t&1;
      int nt=!tt;
      if(!que[tt].size()) return -1;
      que[nt].clear();
      while(que[tt].size()) {
         State st=que[tt].back();
         que[tt].pop_back();
         if(st==State(0,0,H)) return t;
         int r=st.r;
         int c=st.c;
         int d=st.d;
         if(dist[r][c][d]<t) continue;
         for(int i=(d==H?1:0);i<4;i+=2) {
            int nr=r+dir[i][0];
            int nc=c+dir[i][1];
            if(!valid(nr,nc)) continue;
            if(t<dist[nr][nc][d]) {
               que[tt].push_back(State(nr,nc,d));
               dist[nr][nc][d]=t;
            }
         }
         if(gr[r][c]=='#') {
            if(t+1<dist[r][c][!d]) {
               que[nt].push_back(State(r,c,!d));
               dist[r][c][!d]=t+1;
            }
         }
      }
   }
}

int main(void)
{
   scanf("%d %d",&rn,&cn);
   for(int i=0;i<rn;i++)
      scanf("%s",gr[i]);
   printf("%d\n",solve());
   return 0;
}