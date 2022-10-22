#include <iostream>

using namespace std;

int main()
{
long long a,b;
cin>>a>>b;
long long r= (a/2)/(b+1);
cout<<r<<" "<<b*r<<" "<<a-r-b*r;
    return 0;
}