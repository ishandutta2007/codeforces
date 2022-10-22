#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string s1,s2;
int n,m, a[200009];
ll MOD=998244353;
int main()
{
cin>>n>>m>>s1>>s2;
for(int i=m-1;i>=0;i--)
{
a[i]=a[i+1];
if(s2[m-1-i]=='1')a[i]++;

}
ll ans=0;
ll d=1;
for(int i=0;i<n;i++)
{
if(s1[n-1-i]=='1')ans=(ans+a[i]*d)%MOD;
d=(2*d)%MOD;

}
cout<<ans;

    return 0;
}