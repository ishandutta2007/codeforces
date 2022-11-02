#include <stdio.h>
#include <algorithm>
#define MAXN 105

class Thread {
   public:
      int c,id;
      Thread() {}
      Thread(int ci,int ii):c(ci),id(ii) {}
      const bool operator<(const Thread &b) const {
         return c<b.c;
      }
};

int n,w,csum;
Thread s[MAXN];

#define FAIL { puts("No"); return; }

inline void solve_n1() {
   if(w!=s[0].c) FAIL;
   puts("Yes");
   for(int i=0;i<s[0].c;i++)
      printf("1 1 ");
   puts("");
}

inline void solve_nn() {
   if(w>csum) FAIL;
   std::sort(s,s+n);
   if(w==1) {
      if(s[0].c!=1) FAIL;
      puts("Yes");
      printf("%d ",s[0].id);
      for(int i=1;i<n;i++)
         for(int j=0;j<s[i].c;j++)
            printf("%d %d ",s[i].id,s[i].id);
      printf("%d\n",s[0].id);
      return;
   }
   puts("Yes");
   if(w>=s[0].c) {
      for(int i=0;i<s[0].c-1;i++)
         printf("%d %d ",s[0].id,s[0].id);
      printf("%d ",s[0].id);
      int waste=csum-w;
      for(int i=1;i<n;i++) {
         for(int j=0;j<s[i].c;j++) {
            if(waste==0) printf("%d ",s[0].id);
            printf("%d %d ",s[i].id,s[i].id);
            waste--;
         }
      }
      if(waste==0) printf("%d\n",s[0].id);
      puts("");
   } else {
      printf("%d ",s[0].id);
      for(int i=1;i<n;i++)
         for(int j=(i==1?1:0);j<s[i].c;j++)
            printf("%d %d ",s[i].id,s[i].id);
      printf("%d %d ",s[0].id,s[1].id);
      int waste=(s[0].c-1)-(w-2);
      for(int j=1;j<s[0].c;j++) {
         if(waste==0) printf("%d ",s[1].id);
         printf("%d %d ",s[0].id,s[0].id);
         waste--;
      }
      if(waste==0) printf("%d\n",s[1].id);
   }
}

inline void solve() {
   if(w<=0) FAIL;
   if(n==1) solve_n1();
   else solve_nn();
}

int main(void)
{
   scanf("%d %d",&n,&w);
   csum=0;
   for(int i=0;i<n;i++) {
      int c;
      scanf("%d",&c);
      s[i]=Thread(c,i+1);
      csum+=c;
   }
   solve();
}