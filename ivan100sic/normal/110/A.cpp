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

bool jelaki(long long x){
   long cnt=0;
   do{
      if ((x % 10 == 4) || (x % 10 == 7)) cnt++;
      x/=10;
   } while (x>0);
   if (cnt==4 || cnt==7) return true;
   return false;
}

int main(){
   long long br;
   cin >> br;
   if (jelaki(br)) cout << "YES\n"; else cout << "NO\n";
   return 0;
}