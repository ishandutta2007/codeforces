#include <iostream>

using namespace std;
int a, b, c, d, e;
int main()
{
cin>>a>>b>>c>>d>>e;
int sum=a+b+c+d+e;
if(sum==0)
{
    cout<<-1;
    return 0;
}
if(sum%5==0)
    cout<<sum/5;
else cout<<"-1";
    return 0;
}