#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 100050
#define MAXVAL 10000050

using namespace std;

const int limit=10000000;

int an,bn;
int a[MAXN],b[MAXN];

int fac[MAXVAL];
int ca[MAXVAL],cb[MAXVAL];

void gen() {
   fac[1]=1;
   //pn=0;
   for(int i=2;i<MAXVAL;i++) {
      if(fac[i]) continue;
      //pr[pn++]=i;
      fac[i]=i;
      if((long long)i*i>=MAXVAL) continue;
      for(int j=i*i;j<MAXVAL;j+=i)
         fac[j]=i;
   }
}

inline void extract(int x,int *cnt) {
   while(x>1) {
      int pf=fac[x];
      cnt[pf]++;
      x/=pf;
   }
}

inline void reduce(int &x,int *cnt) {
   int tx=x;
   while(tx>1) {
      int pf=fac[tx];
      if(cnt[pf]) {
         cnt[pf]--;
         x/=pf;
      }
      tx/=pf;
   }
}

void output() {
   for(int i=0;i<an;i++)
      reduce(a[i],cb);
   for(int i=0;i<bn;i++)
      reduce(b[i],ca);
   printf("%d %d\n",an,bn);
   for(int i=0;i<an;i++)
      printf("%d%c",a[i],i+1<an?' ':'\n');
   for(int i=0;i<bn;i++)
      printf("%d%c",b[i],i+1<bn?' ':'\n');
   /*int ma=1,mb=1;
   vector<int> as,bs;
   for(int p=2;p<MAXVAL;p++) {
      if(!cnt[p]) continue;
      if(cnt[p]>0) {
         for(int i=0;i<cnt[p];i++) {
            if(ma*(long long)p>limit) {
               as.push_back(ma);
               ma=1;
            }
            ma*=p;
         }
      } else {
         for(int i=0;i<-cnt[p];i++) {
            if(mb*(long long)p>limit) {
               bs.push_back(mb);
               mb=1;
            }
            mb*=p;
         }
      }
   }
   if(ma>1) as.push_back(ma);
   if(mb>1) bs.push_back(mb);
   printf("%d %d\n",(int)as.size(),(int)bs.size());
   for(int i=0;i<as.size();i++)
      printf("%d%c",as[i],i+1<as.size()?' ':'\n');
   for(int i=0;i<bs.size();i++)
      printf("%d%c",bs[i],i+1<bs.size()?' ':'\n');*/
}

int main(void)
{
   gen();
   scanf("%d %d",&an,&bn);
   for(int i=0;i<an;i++) {
      scanf("%d",a+i);
      extract(a[i],ca);
   }
   for(int i=0;i<bn;i++) {
      scanf("%d",b+i);
      extract(b[i],cb);
   }
   output();
   return 0;
}