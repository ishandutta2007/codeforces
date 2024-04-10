#include <iostream>

using namespace std;
char s[6][9];
int n, k, cn;
int main()
{

cin>>n;
cn=n;
int a=1;
while(n>0)
{cn=n;
n=n-5*a;
a=a*2;
}
a=a/2;
k=(cn-1)/a;
if(k==0)cout<<"Sheldon";
if(k==1)cout<<"Leonard";
if(k==2)cout<<"Penny";
if(k==3)cout<<"Rajesh";
if(k==4)cout<<"Howard";


    return 0;
}