#include <iostream>

using namespace std;
int a, b;
int main()
{
cin>>a>>b;
for(int i=b+1;i<=b+a+1;i++)
cout<<i<<' ';
for(int i=b;i>0;i--)
    cout<<i<<' ';
    return 0;
}