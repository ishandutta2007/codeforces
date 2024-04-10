#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a;
    int b;
    cin>>b>>a;
    if (b==1&&a=="10")cout<<-1; else{
    while (a.length()<b)
    {
        a+='0';
    }
    cout<<a;}

    return 0;
}