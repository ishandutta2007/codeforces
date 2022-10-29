#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,g,t,f=0,i;
    char a[101];
    cin>>n>>k>>g>>t;
    gets(a);
    for(i=0;i<n;++i)
    {
       if(a[i]=='G') g=i;
       if(a[i]=='T') t=i;
    }
    for(i=g;i<n;i+=k)
    {
        if(i==t) f=1;
        if(a[i]=='#') break;
    }
    for(i=g;i>=0;i-=k)
    {
        if(i==t) f=1;
        if(a[i]=='#') break;
    }
    if(f==1) cout<<"YES";
    else cout<<"NO";
    return 0;
}