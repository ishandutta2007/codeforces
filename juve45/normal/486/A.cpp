#include <iostream>

using namespace std;

int main()
{long long a;
cin>>a;
if(a%2==0)
cout<<a/2;
else
{
    a--;
    cout<<a/2-a-1;
}
    return 0;
}