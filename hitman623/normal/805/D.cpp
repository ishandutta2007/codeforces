#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
    long long n,i,ans=0,h=1000000007,c=0,d=2;
    string s;
    cin>>s;
    n=s.length();
    for(i=n-1;i>=0;--i)
    if(s[i]=='b') c=(c+1)%h;
    else {ans+=c%h;c=(d*c)%h;ans%=h;}
    cout<<ans%h;
    return 0;
}