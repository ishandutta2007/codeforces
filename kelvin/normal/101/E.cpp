#include <stdio.h>
#include <iostream>
#define MAXL 20050

#define DOWN 'C'
#define RIGHT 'S'

int rn,cn,mod;
int rval[MAXL],cval[MAXL];
int mid[MAXL];

long long opt;
long long dpu[2][MAXL],dpd[2][MAXL];

char str[MAXL];

inline int add(int a,int b) { return a+b<mod?a+b:a+b-mod; }
inline int getval(int r,int c) { return add(rval[r],cval[c]); }
inline long long max(long long a,long long b) { return a>b?a:b; }

inline void go(int r1,int r2,int c1,int c2,int x) {
   //printf("<%d %d %d %d, %d>\n",r1,r2,c1,c2,x);
   int rm=(r1+r2)>>1;
   int len=r2-r1+c2-c1;
   if(r1==r2) {
      for(int i=0;i<len;i++)
         str[x+i]=RIGHT;
      if(r1==0&&r2==rn-1) {
         opt=0;
         for(int i=c1;i<=c2;i++)
            opt+=getval(0,i);
      }
      return;
   }
   int cm;
   long long best=-1;
   for(int i=r1;i<=rm;i++)
      for(int j=c1;j<=c2;j++)
         dpu[i&1][j]=getval(i,j)+max(i>r1?dpu[i-1&1][j]:0,j>c1?dpu[i&1][j-1]:0);
   for(int i=r2;i>rm;i--)
      for(int j=c2;j>=c1;j--)
         dpd[i&1][j]=getval(i,j)+max(i<r2?dpd[i+1&1][j]:0,j<c2?dpd[i&1][j+1]:0);
   for(int j=c1;j<=c2;j++) {
      if(dpu[rm&1][j]+dpd[rm+1&1][j]>best) {
         best=dpu[rm&1][j]+dpd[rm+1&1][j];
         cm=j;
      }
   }
   int tl=rm-r1+cm-c1;
   go(r1,rm,c1,cm,x);
   str[x+tl]=DOWN;
   go(rm+1,r2,cm,c2,x+tl+1);
   if(r1==0&&r2==rn-1) opt=best;
}

inline void solve() {
   go(0,rn-1,0,cn-1,0);
   std::cout << opt << std::endl;
   str[rn+cn-2]='\0';
   puts(str);
}

int main(void)
{
   while(scanf("%d %d %d",&rn,&cn,&mod)==3) {
      for(int i=0;i<rn;i++) {
         scanf("%d",rval+i);
         rval[i]%=mod;
      }
      for(int i=0;i<cn;i++) {
         scanf("%d",cval+i);
         cval[i]%=mod;
      }
      solve();
   }
   return 0;
}