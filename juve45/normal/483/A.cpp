#include <iostream>

using namespace std;
long long a, r;
int main()
{
cin>>a>>r;

if(a%2==0)
{
    if(a+2>r)cout<<-1<<'\n';
    else
    cout<<a<<' '<<a+1<<' '<<a+2<<'\n';
}
else
{
    if(a+3>r) cout<<-1<<'\n';
    else
    cout<<a+1<<' '<<a+2<<' '<<a+3<<'\n';
}
    return 0;
}