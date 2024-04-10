#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n,m;
vector<ll>a;
int main()
{ios::sync_with_stdio(0);
cin>>n>>m;
if(n==1&&m>0){cout<<-1;return 0;}
if(n==1){cout<<1;return 0;}
a.push_back(1);
a.push_back(2);
ll h=3;
for(int i=2;i<n;i++)
{
    if(m==0){a.push_back(a[i-1]+h);continue;}
ll q=max((ll)0,i-2*m);
a.push_back(a[i-1]+a[q]);
m-=(i-q)/2;
if(m==0)h=a[i]+1;
}
if(m>0){cout<<-1;return 0;}
for(int i=0;i<n;i++)cout<<a[i]<<" ";
    return 0;
}