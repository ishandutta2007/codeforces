
#include <iostream>

using namespace std;

int main()
{
    int n,i;
    char a[]="I hate",b[]="I love",c[]=" that ",d[]=" it";
    cin>>n;
    for(i=0;i<n;++i)
    {
        if(i%2==0) cout<<a;
        else cout<<b;
        if(i<n-1)cout<<c;
    }
    cout<<d;
    return 0;
}