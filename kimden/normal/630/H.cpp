#include <iostream>
using namespace std;
int main(){
   int n;
   long long k=1;
   cin >> n;
   for(int i=1;i<=5;i++){
      k*=n;
      k/=i;
      k*=n;
      n--;
   }
   cout << k;
   return 0;
}