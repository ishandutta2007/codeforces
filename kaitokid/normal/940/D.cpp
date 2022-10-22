#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,a[100009],r=1e9,l=-1*1e9;
string b;
int main()
{
    ios::sync_with_stdio(0);
cin>>n;
for(int i=0;i<n;i++)cin>>a[i];
    cin>>b;
    for(int i=4;i<n;i++)
    {
        if(b[i]==b[i-1])continue;
        if(b[i]=='1')for(int j=0;j<5;j++)l=max(l,a[i-j]+1);
        if(b[i]=='0')for(int j=0;j<5;j++)r=min(r,a[i-j]-1);
    }
    cout<<l<<" "<<r;
return 0;
}