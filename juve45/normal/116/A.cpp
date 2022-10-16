#include <iostream>

using namespace std;
int n, a, b;
int main()
{
    cin>>n;
    int s=0, smax=0;
    for(int i=1;i<=n;++i)
    {
        cin>>a>>b;
        s=s-a+b;
        if(s>smax)
            smax=s;
    }
    cout<<smax;

    return 0;
}