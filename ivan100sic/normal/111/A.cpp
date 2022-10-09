#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>5
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

long long A[110000],N,i,j,k,x,y;
char S[110000],C;

int main(){
   cin >> N;
   cin >> x;
   cin >> y;
   k = y-N+1;
   if (k<1 || k*k+N-1 < x){
      printf("-1\n");
      return 0;
   } else {
      cout << k << "\n";
      for (i=1; i<N; i++) printf("1\n");
      return 0;
   }
}