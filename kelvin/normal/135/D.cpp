#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAXL 1050
//#define DEBUG

using namespace std;

int adj4[4][2]={1,0, 0,1, -1,0, 0,-1};
int adj8[8][2]={1,0, 0,1, -1,0, 0,-1, 1,1, 1,-1, -1,1, -1,-1};

int rn,cn;
char gr[MAXL][MAXL];

int dc;
bool v4[MAXL][MAXL]={0};
bool v8[MAXL][MAXL]={0};

typedef pair<int,int> pii;

bool bad;
int bd[MAXL][MAXL]={0},bi=0;
int vis[MAXL][MAXL]={0},vid=0;
vector<pii> bv;

inline bool valid(int r,int c) { return r>=0&&r<rn&&c>=0&&c<cn; }

inline bool check(int r,int c) {
   int cnt=0;
   for(int i=0;i<4;i++) {
      int nr=r+adj4[i][0];
      int nc=c+adj4[i][1];
      if(!valid(nr,nc)) continue;
      if(bd[nr][nc]==bi) cnt++;
   }
   return cnt==2;
}

void dfs(int r,int c,int type) {
   dc++;
   if(type==4) v4[r][c]=1;
   else v8[r][c]=1;
   for(int i=0;i<type;i++) {
      int nr,nc;
      if(type==4) {
         nr=r+adj4[i][0];
         nc=c+adj4[i][1];
      } else {
         nr=r+adj8[i][0];
         nc=c+adj8[i][1];
      }
      if(!valid(nr,nc)) {
         bad=1;
         continue;
      }
      if(gr[nr][nc]=='1') {
         if(type==8&&bd[nr][nc]<bi) {
            bd[nr][nc]=bi;
            bv.push_back(make_pair(nr,nc));
         }
         continue;
      }
      if(type==4) {
         if(v4[nr][nc]) continue;
      } else {
         if(v8[nr][nc]) continue;
      }
      dfs(nr,nc,type);
   }
}

void bdfs(int r,int c) {
   dc++;
   vis[r][c]=vid;
   for(int i=0;i<4;i++) {
      int nr=r+adj4[i][0];
      int nc=c+adj4[i][1];
      if(!valid(nr,nc)) continue;
      if(gr[nr][nc]!='1') continue;
      if(vis[nr][nc]==vid) continue;
      if(bd[nr][nc]!=bi) continue;
      bdfs(nr,nc);
   }
}

inline bool checkadj() {
   for(int i=0;i<bv.size();i++)
      if(!check(bv[i].first,bv[i].second)) return 0;
   return 1;
}

inline int solve() {
   int opt=0;
   for(int i=0;i<rn-1;i++)
      for(int j=0;j<cn-1;j++)
         if(gr[i][j]=='1'&&gr[i][j+1]=='1'&&gr[i+1][j]=='1'&&gr[i+1][j+1]=='1') opt=4;
   for(int i=0;i<rn;i++) {
      for(int j=0;j<cn;j++) {
         if(gr[i][j]=='1') continue;
         if(v8[i][j]) continue;
         int c4,c8;
         bi++;
         bv.clear();
         bad=0;
         dc=0;
         dfs(i,j,8);
         c8=dc;
         if(bad) continue;
         /*dc=0;
         dfs(i,j,4);
         c4=dc;*/
         if(bv.size()==0) return 0;
#ifdef DEBUG
         printf("%d %d: <%d %d>\n",i,j,c4,c8);
#endif
         //if(c4!=c8) continue;
         if(!checkadj()) continue;
#ifdef DEBUG
         printf("<adj ok!>\n");
#endif
         dc=0;
         ++vid;
         bdfs(bv[0].first,bv[0].second);
#ifdef DEBUG
         printf("<%d %d>\n",dc,bv.size());
#endif
         if(dc!=bv.size()) continue;
#ifdef DEBUG
         printf("<dc ok!>\n");
#endif
         if(dc>opt) opt=dc;
      }
   }
   return opt;
}

int main(void)
{
   scanf("%d %d",&rn,&cn);
   for(int i=0;i<rn;i++)
      scanf("%s",gr[i]);
   printf("%d\n",solve());
   return 0;
}