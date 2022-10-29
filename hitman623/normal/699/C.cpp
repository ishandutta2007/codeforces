#include <bits/stdc++.h>

using namespace std;

int main()
{
    long n,a[105],i,cur=0,c=0;
    cin>>n;
    for(i=0;i<n;++i)
        cin>>a[i];
    for(i=0;i<n;++i)
    {
        if(a[i]==1) {if(cur==1)a[i]=0;cur=1;}
        if(a[i]==2) {if(cur==2) a[i]=0;cur=2;}
        if(a[i]==3)
        {
            if(cur==1) {a[i]=2;cur=2;continue;}
            if(cur==2) {a[i]=1;cur=1;continue;}
        }
        if(a[i]==0) cur=0;
    }
    for(i=0;i<n;++i)
    {//cout<<a[i]<<" ";
    if(!a[i]) c++;}
    cout<<c;
    return 0;
}