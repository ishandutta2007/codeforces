#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;

long Posl[101000],Del[1000],N,i,j,k,l,x,y,d,c;

int main(){
   memset(Posl,255,sizeof(Posl));
   scanf("%ld",&N);
   for (i=1; i<=N; i++){
      l=0;
      c=0;
      scanf("%ld%ld",&x,&y);
      for (j=1; j*j<=x; j++){
         if (x%j==0){
            l++;
            Del[l]=j;
         }
      }
      if (Del[l]*Del[l]==x) d=l-1; else d=l;
      for (j=1; j<=d; j++) Del[j+l]=x/Del[j];
      l+=d;
      for (j=1; j<=l; j++){
         if (Posl[Del[j]] >= i-y) c++;
      }
      for (j=1; j<=l; j++) Posl[Del[j]]=i;
      printf("%ld\n",l-c);
   }
}