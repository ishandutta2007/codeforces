#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#define exit(i) cout << i; return 0
using namespace std;
int main(){
   int a[9];
   int state=0;
   cin >> a[0] >> a[1] >> a[2] >> a[3];
   a[4]=a[0];
   a[5]=a[1];
   a[6]=a[2];
   for(int i=0;i<4;i++){
      if(a[i]<a[i+1]+a[i+2] && a[i+1]<a[i+2]+a[i] && a[i+2]<a[i]+a[i+1]){
         state=max(state,2);
      }else if(a[i]==a[i+1]+a[i+2] || a[i+1]==a[i+2]+a[i] || a[i+2]==a[i]+a[i+1]){
         state=max(state,1);
      }
   }
   switch(state){
      case 2: cout << "TRIANGLE"; return 0;
      case 1: cout << "SEGMENT"; return 0;
      case 0: cout << "IMPOSSIBLE"; return 0;
   }
   return 0;
}