#include <stdio.h>
#include <string.h>

const int adj[9][2]={1,0, 0,1, -1,0, 0,-1, 1,1, -1,-1, 1,-1, -1,1, 0,0};

char gr[8][10];
bool visit[10][8][8];

inline bool valid(int r,int c) {
   return r>=0&&r<8&&c>=0&&c<8;
}

inline bool bad(int r,int c) {
   return valid(r,c)&&gr[r][c]=='S';
}

inline bool solve() {
   memset(visit,0,sizeof(visit));
   visit[0][7][0]=1;
   for(int t=0;t<9;t++) {
      for(int i=0;i<8;i++) {
         for(int j=0;j<8;j++) {
            if(!visit[t][i][j]) continue;
            //printf("<%d %d %d>\n",t,i,j);
            for(int a=0;a<9;a++) {
               int ni=i+adj[a][0];
               int nj=j+adj[a][1];
               if(!valid(ni,nj)) continue;
               if(bad(ni-t,nj)) continue;
               if(bad(ni-t-1,nj)) continue;
               visit[t+1][ni][nj]=1;
            }
         }
      }
   }
   for(int i=0;i<8;i++)
      for(int j=0;j<8;j++)
         if(visit[9][i][j]) return 1;
   return 0;
}

int main(void)
{
   for(int i=0;i<8;i++)
      scanf("%s",gr[i]);
   puts(solve()?"WIN":"LOSE");
   return 0;
}