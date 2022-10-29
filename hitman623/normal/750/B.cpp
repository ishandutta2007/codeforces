#include <bits/stdc++.h>

using namespace std;

int main()
{
    long n,b[100],i,f=1,s=0;
    char a[100][20];
    cin>>n;
    for(i=0;i<n;i++)
        cin>>b[i]>>a[i];
    for(i=0;i<n;++i)
    {
        if(s==0)
            if(a[i][0]!='S') f=0;
        if(s==20000)
            if(a[i][0]!='N') f=0;
            if(s<0 || s>20000) f=0;
        if(a[i][0]=='S') s+=b[i];
        if(a[i][0]=='N') s-=b[i];
    }
    if(s!=0) f=0;
    if(f) cout<<"YES";
    else cout<<"NO";
    return 0;
}