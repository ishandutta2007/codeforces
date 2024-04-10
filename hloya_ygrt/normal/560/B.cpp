#include <iostream> 
using namespace std; 
int main(){ 
int a1,b1,a2,b2,a3,b3;
 int o=0; 
cin>>a1>>b1;
cin>>a2>>b2;
cin>>a3>>b3;
 if (a2+a3<=a1&&b1>=b2&&b1>=b3) o=1; else
 if (b2+b3<=b1&&a1>=a2&&a1>=a3) o=1; else
 if (a2+b3<=a1&&b1>=b2&&b1>=a3) o=1; else
 if (b2+a3<=b1&&a1>=a2&&a1>=b3) o=1; else
 if (b2+a3<=a1&&b1>=a2&&b1>=b3) o=1; else 
if (a2+b3<=b1&&a1>=b2&&a1>=a3) o=1; else 
if (b2+b3<=a1&&b1>=a2&&b1>=a3) o=1; else 
if (a2+a3<=b1&&a1>=b2&&a1>=b3) o=1;
if (o==1) cout<<"YES"; 
else cout<<"NO"; 
return 0;
 }