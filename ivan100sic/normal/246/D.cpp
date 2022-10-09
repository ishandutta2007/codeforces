#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

int C[100005],N,M,i,j,k,mce;
set <int> O[100005];

int main(){
   scanf("%d%d",&N,&M);
   mce=9999999;
   for (i=1; i<=N; i++){
      scanf("%d",C+i);
      mce = min(mce,C[i]);
   }
   for (i=1; i<=M; i++){
      scanf("%d%d",&j,&k);
      j=C[j];
      k=C[k];
      if (j!=k) O[j].insert(k);
      if (j!=k) O[k].insert(j);
   }
   k=mce;
   for (i=1; i<=100000; i++){
      //if (i<10) printf("%d %d %d %d\n",k,O[k].size(),i,O[i].size());
      if (O[i].size() > O[k].size()) k=i;
   }
   printf("%d\n",k);
   return 0;
}