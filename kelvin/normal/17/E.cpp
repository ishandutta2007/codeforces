#include <stdio.h>
#define MAXL 2000050

const int mod=51123987;

int len,sel;
char s[MAXL],se[MAXL*2];
int pal[MAXL*2];

int st[MAXL],st2[MAXL];
int ed[MAXL],ed2[MAXL];

inline int min(int a,int b) { return a<b?a:b; }
inline int max(int a,int b) { return a>b?a:b; }

inline void genpal() {
   int i,j,r,t;
   sel=2*len+1;
   for(i=0;i<sel;i++)
      se[i]=(i&1)?s[i>>1]:'*';
   pal[0]=0;
   j=r=0;
   for(i=1;i<sel;i++) {
      t=min(r>=i?pal[2*j-i]:0,r-i+1);
      for(;i-t>=0&&i+t<sel;t++)
         if(se[i-t]!=se[i+t]) break;
      pal[i]=--t;
      if(i+t>r) {
         r=i+t;
         j=i;
      }
   }
}

inline void genseg() {
   for(int i=0;i<=len;i++)
      st[i]=st2[i]=ed[i]=ed2[i]=0;
   for(int i=1;i<2*len;i++) {
      int l=(i-pal[i]+1)>>1;
      int r=(i+pal[i]-1)>>1;
      if(r<l) continue;
      st2[l]++;
      ed2[r+2]--;
      if(i&1) {
         st2[(i>>1)+1]--;
         ed2[(i>>1)+1]++;
      } else {
         st2[(i>>1)]--;
         ed2[(i>>1)+1]++;
      }
   }
   for(int i=0;i<len;i++) {
      st[i]=(i?st[i-1]:0)+st2[i];
      ed[i]=(i?ed[i-1]:0)+ed2[i];
   }
}

inline int add(int a,int b) { return a+b<mod? a+b:a+b-mod; }
inline int sub(int a,int b) { return a<b? a-b+mod:a-b; }

inline int count() {
   int cur=0,sol=0;
   for(int i=0;i<len;i++) {
      //printf("(%d:%d,%d) ",i,st[i],ed[i]);
      cur=sub(cur,ed[i]);
      sol=add(sol,(long long)cur*st[i]%mod);
      sol=add(sol,(long long)st[i]*(st[i]-1)/2%mod);
      cur=add(cur,st[i]);
   }
   return sol;
}

inline int solve() {
   genpal();
   genseg();
   return count();
}

int main(void)
{
   scanf("%d",&len);
   gets(s); gets(s);
   printf("%d\n",solve());
}