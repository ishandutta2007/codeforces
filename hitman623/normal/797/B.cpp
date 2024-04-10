#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
    long n,a[100005],i,s=0,x=1e9;
    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>a[i];
        if(a[i]>0)
        s+=a[i];
        if(abs(a[i])%2==1 && abs(a[i])<abs(x))
            x=a[i];
    }
    if(s%2==0)
    {
        if(x==1e9) {cout<<0;exit(0);}
        if(x>0)
        cout<<s-x;
        else cout<<s+x;
    }
    else cout<<s;
    return 0;
}