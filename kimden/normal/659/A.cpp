#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
   int n,a,b,k;
   cin >> n >> a >> b;
   k = a+b;
   while(k<=0)
      k+=n;
   while(k>n)
      k-=n;
   cout << k;
   return 0;
}