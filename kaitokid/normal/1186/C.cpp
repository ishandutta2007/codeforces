#include <bits/stdc++.h>

using namespace std;
string a,b;
int ans,d,res;
int main()
{
    ios::sync_with_stdio(0);
    cin>>a>>b;
    for(int i=0;i<b.size()-1;i++)
        if(b[i]!=b[i+1])d++;
        d%=2;
    for(int i=0;i<b.size();i++)if(a[i]!=b[i])res++;
    res%=2;
    if(res==0)ans++;
    for(int i=1;i<a.size()-b.size()+1;i++)
    {
        if(a[i-1]==b[0])res=1-res;
        if(a[i+b.size()-1]==b[b.size()-1])res=1-res;
        if(d==1)res=1-res;
        if(res==0)ans++;
    }
    cout<<ans;
    return 0;
}