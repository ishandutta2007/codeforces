#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAXL 100050

int kth,len;
char s[MAXL];

int hn,head[MAXL];
int tn,tmp[MAXL];
char sol[MAXL];

int sh;
inline bool cmp(int a,int b) {
   return s[a+sh]<s[b+sh];
}

inline void solve() {
   if((long long)len*(len+1)/2<kth) {
      puts("No such line.");
      return;
   }
   kth--;
   hn=0;
   for(int i=0;i<len;i++)
      head[hn++]=i;
   for(int x=0;;x++) {
      sh=x;
      std::sort(head,head+hn,cmp);
      //printf("<%d> %d:\n",x,kth);
      //for(int t=0;t<hn;t++)
         //printf("%d ",head[t]);puts("");
      int j;
      for(int i=0;i<hn;i=j) {
         int cnt=0,tail=0;
         for(j=i;j<hn&&!cmp(head[i],head[j]);j++) {
            cnt++;
            tail+=len-(head[j]+x)-1;
         }
         //printf("(%d %d)\n",cnt,tail);
         if(kth<cnt) {
            sol[x]=s[head[i]+x];
            sol[x+1]='\0';
            puts(sol);
            return;
         }
         kth-=cnt;
         if(kth<tail) {
            sol[x]=s[head[i]+x];
            hn=0;
            for(int t=i;t<j;t++)
               if(head[t]+x+1<len) head[hn++]=head[t];
            continue;
         }
         kth-=tail;
      }
   }
}

int main(void)
{
   scanf("%s",s);
   scanf("%d",&kth);
   len=strlen(s);
   solve();
}