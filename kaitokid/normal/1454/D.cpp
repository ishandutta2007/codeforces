#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<int> a[200009];

int main()
{ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t,n;
    cin>>t;
    while(t--)
    {
ll n;
cin>>n;
ll x=n;
ll u=1,f=0;
for(int i=2;i<=sqrt(n);i++)
{
    if(x%i)continue;
    ll d=0;
    while(x%i==0)
    {
        x/=i;
        d++;
    }

    if(d>f){u=i;f=d;}

}

if(x>1)
{
    if(f==0){f=1;u=x;}
}
cout<<f<<endl;
for(int i=0;i<f-1;i++)
{
    cout<<u<<" ";
    n/=u;
}
cout<<n<<endl;

    }
    return 0;
}