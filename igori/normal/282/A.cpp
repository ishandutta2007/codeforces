#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a;
    cin>>a;
    int x=0;
    char now;
    for(int i=0; i<3*a; i++)
    {
        cin>>now;
        if(now=='+')
            x=x+5;
        if(now=='-')
            x=x-5;
            
    }
    cout<<x/10;
}