#include <bits/stdc++.h> 
using namespace std ;
int ans;
int a[5009],b[5009],a2[5009],b2[5009];
int main()
{ios::sync_with_stdio(0);
string s;

cin>>s;
for(int i=0;i<s.size();i++)
{
a[i]=a[i-1];
b[i]=b[i-1];
if(s[i]=='a')a[i]++;
else b[i]++;


}
for(int i=s.size()-1;i>=0;i--)
{
a2[i]=a2[i+1];
b2[i]=b2[i+1];
if(s[i]=='a')a2[i]++;
else b2[i]++;


}

ans=b[s.size()-1];
for(int i=0;i<s.size()-1;i++)
ans=min(ans,a[i]+b2[i+1]);
ans=min(ans,a[s.size()-1]);
for(int i=1;i<s.size();i++)
{
for(int j=i;j<s.size();j++)
{ans=min(ans,b[i-1]+b2[j+1]+a[j]-a[i-1]);}



}
cout<<s.size()-ans;
return 0;}