#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
ll t;
cin>>t;
while(t--)
{
    ll n;
    cin>>n;
    ll mn=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]<a[mn])mn=i;
    }
cout<<n-1<<endl;
int st;
if(mn%2==0)st=2;
else st=1;
for(int i=st;i<mn;i+=2)
    cout<<i<<" "<<mn<<" "<<a[mn]<<" "<<a[mn]<<endl;
for(int i=mn+2;i<=n;i+=2)
    cout<<i<<" "<<mn<<" "<<a[mn]<<" "<<a[mn]<<endl;
 if(st==1)st=2;else st=1;
for(int i=st;i<mn;i+=2)
    cout<<i<<" "<<mn<<" "<<a[mn]+1<<" "<<a[mn]<<endl;
for(int i=mn+1;i<=n;i+=2)
    cout<<mn<<" "<<i<<" "<<a[mn]<<" "<<a[mn]+1<<endl;


}

    return 0;
}