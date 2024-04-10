#include <bits/stdc++.h>
using namespace std;

int mx=-1,mn=100009;
int ans;
int main()
{ios::sync_with_stdio(0);
int n,p;
string s;
cin>>n>>p>>s;
for(int i=0;i<n/2;i++)
{
int l=abs(s[i]-s[n-i-1]);

ans+=min(l,26-l);
if(s[i]!=s[n-i-1]){mx=max(mx,i);mn=min(mn,i);}

}
p--;
p=min(p,n-p-1);
if(mn==100009)mn=p;
if(mx==-1)mx=p;
if(mn>=p){ans+=mx-p;cout<<ans;return 0;}
if(mx<=p){ans+=p-mn;cout<<ans;return 0;}
ans+=mx-mn;
ans+=min(mx-p,p-mn);
cout<<ans;
return 0;}