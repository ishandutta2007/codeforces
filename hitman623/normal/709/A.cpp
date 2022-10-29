#include <iostream>

using namespace std;

int main()
{
    long n,b,d,a[100000],i,c=0,s=0;
    cin>>n>>b>>d;
    for(i=0;i<n;++i)
        cin>>a[i];
    for(i=0;i<n;++i)
    {
        if(a[i]<=b)
            s+=a[i];
         if(s>d) {c++;s=0;}
    }
    cout<<c;
    return 0;
}