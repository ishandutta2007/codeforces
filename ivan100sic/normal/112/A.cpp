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

long N,i,j,k;
char S[110000],S2[110000],C;

int main(){
   scanf("%s",S);
   scanf("%s",S2);
   for (j=0; j<1000; j++){
      if (S[j]<95) S[j]+=32;
      if (S2[j]<95) S2[j]+=32;
   }
   while (S[i]==S2[i] && i<130) i++;
   if (i==130) printf("0\n"); else {
      if (S[i]>S2[i]) printf("1"); else printf("-1\n");
   }
   return 0;
}