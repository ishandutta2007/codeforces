#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#define shit 1684300900
using namespace std;

long D[110000],N,i,j,k;

int main(){
   cin >> N;
   /*/memset(D,100,sizeof(D));
   cout << D[0];
   for (i=1; i<=N; i++){
      if (i<3) continue;
      D[i] = min(D[i-4],D[i-7]);
   }*/
      j=0;
      k=0;
      while (N % 7 !=0) {
         j++;
         N-=4;
      }
      k = N/7;
      if (j < 0 || k < 0){
         cout << "-1\n";
         return 0;
      }
      for (i=1; i<=j; i++) cout << "4";
      for (i=1; i<=k; i++) cout << "7";
      cout << "\n";
      return 0;
}