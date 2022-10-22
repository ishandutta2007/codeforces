#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,a[500009],d[500009],x,s[500009];
multiset<ll>g;
int main()
{
    ios::sync_with_stdio(0);
cin>>n;
ll m=(n+1)/2;
for(ll i=0;i<m;i++)
    {cin>>a[i];
s[i]=s[i-1]+a[i];}
 cin>>x;

 for(int i=m-1;i>=0;i--){d[i]=a[i]-x+d[i+1];g.insert(d[i]);}
       ll u=(n-m)*x,w=(n-m);
    //if(n%2==1&&x>0&&s[m-1]>0&&u+a[m-1]>0){cout<<m;return 0;}


    //if(n%2==1&&m>1&&s[m-2]>0&&s[m-1]-a[0]>0&&x>0){cout<<m-1;return 0;}


    for(int i=m-1;i>=0;i--)
    {
        w++;
        u+=a[i];
        g.erase(g.lower_bound(d[i]));
       if(u<=0)continue;
       if(i==0){cout<<w;return 0;}
    ll p=(*g.begin());
    if(u+p-d[i]>0){cout<<w;return 0;}

    }
    cout<<-1;
    return 0;
}