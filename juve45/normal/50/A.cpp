#include <iostream>

using namespace std;

int main()
{int a,b;
cin>>a>>b;
int ca=a;
int cb=b;
int k=a/2;
int g=b/2;
a=a-2*k;
b=b-2*g;
cout<<k*g*2+a*cb/2+b*ca/2;
    return 0;
}