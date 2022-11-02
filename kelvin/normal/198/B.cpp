#include <cstdio>
#include <algorithm>
#define MAXL 100050

using namespace std;

typedef pair<int,int> pii;

int n,k;
char wall[2][MAXL*2];
bool vis[2][MAXL*2]={0};
int dist[2][MAXL*2]={0};

int ql,qr;
pii que[MAXL*4];

bool solve() {
   ql=qr=0;
   que[qr++]=make_pair(0,0);
   vis[0][0]=1;
   dist[0][0]=0;
   while(ql<qr) {
      int s=que[ql].first;
      int h=que[ql].second;
      int d=dist[s][h];
      ql++;
      if(h>=n) return 1;
      int ns,nh,nd;
#define CHECKIT \
      if(nh>=0&&!vis[ns][nh]&&nd<=nh&&(nh>=n||wall[ns][nh]=='-')) { \
         que[qr++]=make_pair(ns,nh); \
         vis[ns][nh]=1; \
         dist[ns][nh]=nd; \
      }
      // down
      ns=s;
      nh=h-1;
      nd=d+1;
      CHECKIT;
      // up
      ns=s;
      nh=h+1;
      nd=d+1;
      CHECKIT;
      // jump
      ns=!s;
      nh=h+k;
      nd=d+1;
      CHECKIT;
   }
   return 0;
}

int main(void)
{
   scanf("%d %d",&n,&k);
   scanf("%s %s",wall[0],wall[1]);
   puts(solve()?"YES":"NO");
   return 0;
}