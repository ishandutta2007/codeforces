#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main(){
   int n,p;
   bool a[50];
   string s;
   cin >> n >> p;
   for(int i=0;i<n;i++)
   {
      cin >> s;
      if(s=="half"){
         a[n-i-1]=false;
      }else{
         a[n-i-1]=true;
      }
   }
   long long k=0;
   long long ans=0;
   for(int i=0;i<n;i++){
      if(a[i]){
         k*=2;
         k+=1;
         ans--;
      }else{
         k*=2;
      }
   }
   ans+=(k*2);
   ans*=(long long)p;
   ans/=2;
   cout << ans;
   return 0;
}