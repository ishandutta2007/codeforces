#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int main(){
   const double pi = acos(-1);
   const double eps = 1e-5;
   double X1,Y1,X2,Y2,X3,Y3;
   cin >> X1 >> Y1 >> X2 >> Y2 >> X3 >> Y3;
   double a,b,c,cosa,cosb,cosc,aa,bb,cc,ans,r;
   c = sqrt((X1-X2)*(X1-X2)+(Y1-Y2)*(Y1-Y2));
   b = sqrt((X1-X3)*(X1-X3)+(Y1-Y3)*(Y1-Y3));
   a = sqrt((X2-X3)*(X2-X3)+(Y2-Y3)*(Y2-Y3));
   cosa = (b*b+c*c-a*a)/(2*b*c);
   cosb = (a*a+c*c-b*b)/(2*a*c);
   cosc = (b*b+a*a-c*c)/(2*b*a);
   aa = acos(cosa) / pi;
   bb = acos(cosb) / pi;
   cc = acos(cosc) / pi;
   int i=1;
   bool a1=false,b1=false,c1=false;
   while((!a1 && !b1)||(!a1 && !c1)||(!c1 && !b1)){
      i++;
	  a1 = fabs(aa*i-floor(aa*i+0.5))<eps;
	  b1 = fabs(bb*i-floor(bb*i+0.5))<eps;
	  c1 = fabs(cc*i-floor(cc*i+0.5))<eps;
      if(i==101){
         cout << "Error\n";
         break;
      }
   }
   r = a/(2*sqrt(1-cosa*cosa));
   ans = 0.5*r*r*sin(2*pi/(double)i)*i;
  //cout << setprecision(6) << r <<"\n"<<i<<"\n";
   printf("%.9f",ans);
   return 0;
}