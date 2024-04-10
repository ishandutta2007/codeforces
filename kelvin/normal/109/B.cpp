#include <stdio.h>
#include <algorithm>
#define MAXN 100000

int an,arr[MAXN];

int l1,r1,l2,r2,k;
const int inf=1000000001;

void dfs(int d,int val) {
   arr[an++]=val;
   if(d==9) return;
   dfs(d+1,val*10+4);
   dfs(d+1,val*10+7);
}

inline void gen() {
   an=0;
   dfs(0,0);
   std::sort(arr,arr+an);
}

inline int min(int a,int b) { return a<b?a:b; }
inline int max(int a,int b) { return a>b?a:b; }
inline bool bet(int x,int l,int r) { return x>=l&&x<=r; }

inline int intersect(int l1,int r1,int l2,int r2) {
   return max(min(r1,r2)-max(l1,l2)+1,0);
}

inline double solve() {
   int i,j,a,b,ll,rr,lb,rb;
   long long cc=0;
   long long dd=(long long)(r1-l1+1)*(r2-l2+1);
   for(i=0;i<an;i++) {
      j=i+k-1;
      if(j>=an) break;
      if(arr[j]>max(r1,r2)) break;
//      printf("<%d %d>\n",arr[i],arr[j]);
      cc+=(long long)intersect(i?arr[i-1]+1:1,arr[i],l1,r1)*intersect(arr[j],j<an-1?arr[j+1]-1:inf,l2,r2);
      cc+=(long long)intersect(i?arr[i-1]+1:1,arr[i],l2,r2)*intersect(arr[j],j<an-1?arr[j+1]-1:inf,l1,r1);
//      printf("<%d %d %lld>\n",i,j,cc);
   }
   if(k==1) {
      for(i=0;i<an;i++)
         if(bet(arr[i],l1,r1)&&bet(arr[i],l2,r2)) cc--;
   }
   return (double)cc/dd;
}

int main(void)
{
   int i;
   gen();
   while(scanf("%d %d %d %d %d",&l1,&r1,&l2,&r2,&k)==5) {
      printf("%.12lf\n",solve());
   }
   return 0;
}