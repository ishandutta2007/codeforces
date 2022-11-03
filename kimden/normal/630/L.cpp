#include <iostream>
using namespace std;
int main(){
   int n;
   long long q;
   int m;
   int a[5];
   cin>>n;
   for(int i=0;i<5;i++){
      a[i]=n%10;
      n/=10;
   }
   n=10000*a[4]+1000*a[2]+100*a[0]+10*a[1]+a[3];
   m=1;
   for(int i=0;i<5;i++){
      q=((long long)n)*((long long)m);
      q%=100000;
      m=(int)q;
   }
   if(m<10000) cout<<0;
   if(m<1000) cout<<0;
   if(m<100)cout<<0;
   if(m<10)cout<<0;
   cout<<m;
   return 0;
}