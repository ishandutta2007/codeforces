#include <iostream>

unsigned long long s,a1,a2,a3,a4,a5,a6,a7,a8,a9,n;
using namespace std;
int main(){
   cin>>n;
   a1=(9-1+1)*1;
   a2=(99-10+1)*2;
   a3=(999-100+1)*3;
   a4=(9999-1000+1)*4;
   a5=(99999-10000+1)*5;
   a6=(999999-100000+1)*6;
   a7=(9999999-1000000+1)*7;
   a8=(99999999-10000000+1)*8;
   a9=(999999999-100000000+1)*9;

   if (n==1000000000) { s=8888888899; cout<<s; return 0; }
   if (n<10) { s=n; cout<<s; return 0; }
   if (n<100) { s=a1+(n-10+1)*2; cout<<s; return 0; }
   if (n<1000) { s=a1+a2+(n-100+1)*3;  cout<<s; return 0; }
   if (n<10000) { s=a1+a2+a3+(n-1000+1)*4; cout<<s; return 0; }
   if (n<100000) { s=a1+a2+a3+a4+(n-10000+1)*5;  cout<<s; return 0; }
   if (n<1000000) { s=a1+a2+a3+a4+a5+(n-100000+1)*6; cout<<s; return 0; }
   if (n<10000000) { s=a1+a2+a3+a4+a5+a6+(n-1000000+1)*7;  cout<<s; return 0; }
   if (n<100000000) { s=a1+a2+a3+a4+a5+a6+a7+(n-10000000+1)*8; cout<<s; return 0; }
   if (n<1000000000) { s=a1+a2+a3+a4+a5+a6+a7+a8+(n-100000000+1)*9;  cout<<s; return 0; }

  cout<<s;
return 0;
}