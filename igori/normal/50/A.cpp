#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a,b,ans;
    cin>>a>>b;
    if((a%2==1)&&(b%2==1))
        cout<<((a*b)-1)/2;
    else
        cout<<(a*b)/2;
}