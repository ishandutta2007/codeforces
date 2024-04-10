#include <iostream>
#include<algorithm>

using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    if(a>b)
        swap(a,b);
    if(a*2<=b)
    {
        cout<<a<<endl;
        return 0;
    }
    cout<<(a+b)/3<<endl;
}