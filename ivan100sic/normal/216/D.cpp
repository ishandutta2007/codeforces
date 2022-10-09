#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int PA[1005],A[100005],N,i,j,k,l,r,o,c1,c2;

int range(int s,int ll,int ul){
   int l,r,m,o1,o2;
   l=PA[s];
   r=PA[s+1]-1;
   o1=-1;
   while (l<=r){
      m = (l+r)/2;
      if (A[m]>ll){
         o1 = m;
         r = m-1;
      } else {
         l = m+1;
      }
   }
   o2=-1;
   l=PA[s];
   r=PA[s+1]-1;
   while (l<=r){
      m = (l+r)/2;
      if (A[m]<ul){
         o2 = m;
         l = m+1;
      } else {
         r = m-1;
      }
   }
   if (o1==-1 || o2==-1) return 0;
   //printf("%d %d %d %d %d\n",s,ll,ul,o1,o2);
   return o2-o1+1;
}

int next(int x){
   if (x<N) return x+1; else return 1;
}

int prev(int x){
   if (x>1) return x-1; else return N;
}

int main(){
   scanf("%d",&N);
   for (i=1; i<=N; i++){
      PA[i] = k+1;
      scanf("%d",&l);
      for (j=1; j<=l; j++){
         k++;
         scanf("%d",&r);
         A[k] = r;
      }
   }
   PA[N+1] = k+1;
   for (i=1; i<=N; i++) sort(A+PA[i] , A+PA[i+1]);
   int sol=0;
   for (i=1; i<=N; i++){
      for (j=PA[i]+1; j<PA[i+1]; j++){
         c1 = range(prev(i) , A[j-1], A[j]);
         c2 = range(next(i) , A[j-1], A[j]);
         if (c1!=c2) sol++;
         //printf("%d %d %d %d\n",i,j,c1,c2);
      }
   }
   printf("%d\n",sol);
   return 0;
}