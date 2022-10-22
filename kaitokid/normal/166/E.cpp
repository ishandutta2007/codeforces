#include <iostream>

using namespace std;

int main()
{
unsigned long long a,x=3,y=0;
cin>>a;
if(a<2){cout<<"0";return 0;}

if(a==2){cout <<"3";return 0;}
for(unsigned long long i=0;i<a-2;i++)
{ if(x>y)y=x-y;
    if (x<y) y=(x-y+1000000007)%1000000007;
    x= (x*3)%1000000007;
//cout<<x<<" "<<y<<endl;
}

if(x>y)cout<<x -y;
else cout<<x-y+1000000007;
    return 0;
}