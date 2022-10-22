#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
string s;
int n;
int a[500009],b[500009];
int main()
{
ios::sync_with_stdio(0);
cin>>n;
for(int i=0;i<n;i++)
{
cin>>s;
int u=0,mn=0;
for(int j=0;j<s.size();j++)
{if(s[j]=='(')u++;
else u--;
mn=min(mn,u);

}
if(u>=0) if(mn<0)continue; else a[u]++;
if(u<0) if(mn<u)continue; else b[-u]++;


}
ll ans=a[0]/2;
for(int i=1;i<=500000;i++)ans+=min(a[i],b[i]);
cout<<ans;
return 0;
}