#include <iostream>

using namespace std;

int main()
{
     long n,a[100000],i,l=1,m=0;
     cin>>n;
        for(i=0;i<n;++i)
            cin>>a[i];
        for(i=1;i<n;++i)
            if(a[i]>a[i-1]) l++;
            else {m=max(l,m);l=1;}
            m=max(l,m);
           cout<<m;
    return 0;
}