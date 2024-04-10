#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int q,n,a[201],st;
int main()
{
ios::sync_with_stdio(0);
cin>>q;
while(q--)
{
bool bl=true;
cin>>n;
for(int i=0;i<n;i++)
{cin>>a[i];if(a[i]==1)st=i;}
if(n==1){cout<<"YES\n";continue;}
int j=(st+1)%n;
if(a[j]==2)
{
while(a[j]!=1)
{
if(a[j]!=a[st]+1){cout<<"NO\n";bl=false;break;}
st=j;
j=(st+1)%n;
}
if(bl)cout<<"YES\n";
continue;

}
if(a[j]==n)
{
st=j;
j=(st+1)%n;
while(a[j]!=n)
{
if(a[j]!=a[st]-1){cout<<"NO\n";bl=false;break;}
st=j;
j=(st+1)%n;
}
if(bl)cout<<"YES\n";
continue;

}

cout<<"NO\n";
}
return 0;}