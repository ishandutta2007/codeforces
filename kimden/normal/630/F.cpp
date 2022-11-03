#include <iostream>
using namespace std;
int main(){
   int n;
   long long k;
   cin>>n;
   k = n*(n-1)*1LL*(n-2)*(n-3)*1LL*(n-4)/120;
   k = k+(k*1LL*(n-5))/6+(k*1LL*(n-5)*1LL*(n-6))/42;
   cout << k;
   return 0;
}