#include <stdio.h>
#include <string.h>
#define MAXL 1050
#define MAXK 100050

const int mod=1000000007;

int len,k;
int pre[MAXL];
char st[MAXL],ed[MAXL],st2[MAXL*2];
int match[MAXL*2];
int dp[2][MAXL]={0};

inline int add(int a,int b) { return a+b<mod?a+b:a+b-mod; }
inline int sub(int a,int b) { return a-b<0?a-b+mod:a-b; }

inline void prekmp(char *p,int pl) {
   int i,x=-1; // match to which position
   pre[0]=-1;
   for(i=1;i<pl;i++) {
      while(x>=0&&p[x+1]!=p[i]) x=pre[x];
      if(p[x+1]==p[i]) x++;
      pre[i]=x;
   }
}

inline void matchkmp(char *s,int sl,char *p,int pl) {
   int i,x=-1; // match to which position
   for(i=0;i<sl;i++) {
      while(x>=0&&p[x+1]!=s[i]) x=pre[x];
      if(p[x+1]==s[i]) x++;
      match[i]=x+1;
      if(match[i]==pl) x=pre[x];
   }
}

inline int solve() {
   strcpy(st2,st);
   strcat(st2,st);
   prekmp(ed,len);
   matchkmp(st2,len*2,ed,len);
   dp[0][0]=1;
   for(int i=0;i<k;i++) {
      int ii=i&1;
      int ni=!ii;
      memset(dp[ni],0,len*sizeof(int));
      int all=0;
      for(int j=0;j<len;j++)
         all=add(all,dp[ii][j]);
      //printf("<%d>\n",all);
      for(int j=0;j<len;j++)
         dp[ni][j]=sub(all,dp[ii][j]);
      //printf("(%d,%d) %d\n",ii,ni,k);
   }
   int sol=0;
   //for(int i=0;i<len;i++)
      //if(match[i]==len) printf(">%d ",i);puts("");
   //puts(st2);puts(ed);
   for(int i=0;i<len;i++)
      if(match[i+len-1]==len) sol=add(sol,dp[k&1][i]);
   return sol;
}

int main(void)
{
   scanf("%s %s %d",st,ed,&k);
   len=strlen(st);
   if(strlen(ed)!=len) {
      puts("0");
      return 0;
   }
   printf("%d\n",solve());
   return 0;
}