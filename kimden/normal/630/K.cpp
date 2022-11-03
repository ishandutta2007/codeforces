#include <iostream>
using namespace std;
int main(){
   long long n;
   long long k;
   cin>>n;
   k=n/210;
   k*=48;
   n%=210;
   while(n>0){
      if((n%2!=0 && n%3!=0)&&(n%5!=0 && n%7!=0)){
         k++;
      }
      n--;
   }
   cout<<k;
   return 0;
}