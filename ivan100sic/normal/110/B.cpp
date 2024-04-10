#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;

int main(){
   char S[4];
   long N,i,j,k;
   cin >> N;
   k=N/4;
   for (i=1; i<=k; i++) cout << "abcd";
   k=N%4;
   for (i=1; i<=k; i++) printf("%c",96+i);
   cout << "\n";
   return 0;
}