#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int val(int k){
   if(k<=45) return 0;
   if(k<=135) return 1;
   if(k<=225) return 2;
   if(k<315) return 3;
   return 0;
}
int norm(long long k){
   if(k<0){
      long long x = (-k)/360;
      return norm(k+(x+2)*360);
   }
   return (int)(k%360);
}
int main(){
   long long n;
   cin >> n;
   n=norm(n);
   cout << val(n);
   return 0;
}