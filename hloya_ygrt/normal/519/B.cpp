#include <iostream>

using namespace std;

int main()
{
    int n,a=0,b=0;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a+=x;
    }
    b=a;
    for (int i=0;i<n-1;i++)
    {
        int x;
        cin>>x;
        a-=x;
    }
    b-=a;
    for (int i=0;i<n-2;i++)
    {
        int x;
        cin>>x;
        b-=x;
    }
    cout<<a<<" "<<b;
    return 0;
}