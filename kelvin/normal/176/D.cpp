#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 2050
#define MAXTOTL 2000500
#define MAXL 2050

using namespace std;

typedef pair<int,int> pii;

int nbase,bufi;
char buf[MAXTOTL],*bs[MAXN];
int bslen[MAXN];

int m,sl;
int h[MAXN];
char s[MAXL];

int lbuf[26][MAXTOTL],*lnext[26][MAXN];
int gnext[26][MAXN];
bool hasch[26][MAXN]={0};

pii dp[MAXL][MAXL];

inline void pre() {
   // find global next
   for(int i=0;i<nbase;i++)
      for(int j=0;j<bslen[i];j++)
         hasch[bs[i][j]-'a'][i]=1;
   for(int z=0;z<26;z++)
      gnext[z][m]=m;
   for(int i=m-1;i>=0;i--) {
      for(int z=0;z<26;z++) {
         if(hasch[z][h[i]]) gnext[z][i]=i;
         else gnext[z][i]=gnext[z][i+1];
      }
   }
   /*for(int i=0;i<m;i++)
      for(int z=0;z<26;z++)
         if(gnext[z][i]<m) printf(">> %d,%d: %d\n",z,i,gnext[z][i]);*/
   // find local next
   for(int i=0;i<nbase;i++) {
      int bl=bslen[i];
      char *str=bs[i];
      for(int z=0;z<26;z++)
         lnext[z][i][bl]=bl;
      for(int j=bl-1;j>=0;j--) {
         for(int z=0;z<26;z++)
            lnext[z][i][j]=lnext[z][i][j+1];
         lnext[str[j]-'a'][i][j]=j;
      }
   }
}

inline void relax(pii &x,pii val) {
   if(val<x) x=val;
}

inline int solve() {
   int opt=0;
   pre();
   for(int i=0;i<=sl;i++)
      for(int j=0;j<=i;j++)
         dp[i][j]=make_pair(m+1,0);
   dp[0][0]=make_pair(0,0);
   for(int i=0;i<sl;i++) {
      int z=s[i]-'a';
      //printf(") %d %d\n",i,z);
      for(int j=0;j<=i;j++) {
         int x=dp[i][j].first;
         int y=dp[i][j].second;
         int xtype=h[x];
         if(x>m) continue;
         //printf("%d %d: (%d,%d)\n",i,j,x,y);
         opt=max(opt,j);
         // match
         int nx=m+1,ny=0;
         if(x<m) {
            int loc=lnext[z][xtype][y];
            if(loc<bslen[xtype]) {
               nx=x;
               ny=loc+1;
            } else {
               int glo=gnext[z][x+1];
               //printf("<%d/%d>\n",glo,m);
               if(glo<m) {
                  nx=glo;
                  ny=lnext[z][h[nx]][0]+1;
               }
            }
            relax(dp[i+1][j+1],make_pair(nx,ny));
         }
         // no match
         relax(dp[i+1][j],dp[i][j]);
      }
   }
   for(int j=0;j<=sl;j++)
      if(dp[sl][j].first<=m) opt=max(opt,j);
   return opt;
}

int main(void)
{
   scanf("%d",&nbase);
   bufi=0;
   for(int i=0;i<nbase;i++) {
      scanf("%s",buf+bufi);
      bs[i]=buf+bufi;
      for(int j=0;j<26;j++)
         lnext[j][i]=lbuf[j]+bufi;
      bslen[i]=strlen(buf+bufi);
      bufi+=bslen[i]+1;
   }
   scanf("%d",&m);
   for(int i=0;i<m;i++) {
      scanf("%d",h+i);
      h[i]--;
   }
   scanf("%s",s);
   sl=strlen(s);
   printf("%d\n",solve());
   return 0;
}