#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[200009],ans,b[200009];
int main()
{
   ios::sync_with_stdio(0);
int n,u=0,x;
cin>>n;
for(int i=0;i<n;i++)
{
    cin>>x;
    a[x]=i;
}
for(int j=0;j<n;j++)
{
    cin>>b[j];


}
u=a[b[n-1]];
for(int i= n-2;i>=0;i--)
{
    if(a[b[i]]>u)ans++;
    u=min(u,a[b[i]]);
}
cout<<ans;

    return 0;
}