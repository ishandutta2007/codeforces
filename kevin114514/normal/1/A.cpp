#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    long long x,y,z;
    cin>>x>>y>>z;
    cout<<((x+z-1)/z)*((y+z-1)/z)<<endl;
    return 0;
}