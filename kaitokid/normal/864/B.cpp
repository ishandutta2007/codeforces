#include <bits/stdc++.h>
using namespace std;
bool vis[200];
int ans;

int main()
{
int n;
string s;
cin>>n>>s;
int l=0;
for(int i=0;i<n;i++)
{
if(int(s[i])<92){memset(vis,0,sizeof vis);l=0;continue;}
if(!vis[int(s[i])])l++;
ans=max(l,ans);
vis[int(s[i])]=1;


}
cout<<ans;
return 0;}