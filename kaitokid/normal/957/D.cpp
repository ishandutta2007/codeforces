#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int a[100009],b[100009];
ll ans;
int main()
{
    ios::sync_with_stdio(0);
cin.tie(0);
int n;
cin>>n;
for(int i=0;i<n;i++)cin>>a[i];
for(int i=n-1;i>=0;i--)b[i]=max(a[i]+1,b[i+1]-1);


for(int i=1;i<n;i++)
{
    if((a[i]+1)<=b[i-1])b[i]=max(b[i],b[i-1]);
    else b[i]=max(b[i],b[i-1]+1);
    ans=ans+(ll)max(b[i]-a[i]-1,0);
}
    cout<<ans;
    return 0;
}