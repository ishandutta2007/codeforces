#include<bits/stdc++.h>
using namespace std;
string a,b;
int main()
{
    cin>>a>>b;
    int t=0;
    for(int i=0;i<b.size()-1;i++)
        if(b[i]!=b[i+1]) t^=1;
    int k=0,ans=0;
    for(int i=0;i<b.size();i++)
        if(a[i]!=b[i]) k^=1;
    if(k==0) ans++;
    for(int i=b.size();i<a.size();i++)
    {
        if(a[i-b.size()]!=b[0]) k^=1;
        if(t) k^=1;
        if(a[i]!=b[b.size()-1]) k^=1;
        if(k==0) ans++;
    }
    printf("%d\n",ans);
}