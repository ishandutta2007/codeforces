#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main(){
   int a,b,c;
   cin>>a>>b>>c;
   double d=sqrt(b*b-4*a*c);
   double x=-(b+d)/2/a;
   double y=-(b-d)/2/a;
   if(a<0){
      swap(x,y);
   }
   cout<<setprecision(9)<<y<<"\n"<<setprecision(9)<<x;
   return 0;
}