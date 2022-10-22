#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
long long n,p[200009],k,x,a,y,b,g;
bool go(int h)
{
    ll rr=k;

    int d1=(h/g);
    int d2=h/a-d1;
    int d3=h/b-d1;

    int j=n-1;

    while(j>n-1-d1)
    {
        rr-=(p[j]/100)*(x+y);
        if(rr<=0)return true;
        j--;

    }

    while(j>n-1-d1-d2)
    {
        rr-=(p[j]/100)*(x);
        if(rr<=0)return true;
    j--;
    }
    while(j>n-1-d1-d2-d3)
    {
        rr-=(p[j]/100)*(y);
        if(rr<=0)return true;
    j--;
    }

    return false;
}
int main()
{
    ios::sync_with_stdio(0);
    int q;
    cin>>q;
    while(q--)
    {cin>>n;
    for(int i=0;i<n;i++)cin>>p[i];
sort(p,p+n);
    cin>>x>>a>>y>>b>>k;
    g=(b*a)/(__gcd(a,b));
    if(y>x){int ss=a;a=b;b=ss;ss=y;y=x;x=ss;}
int l=1,r=n;
if(!go(n)){cout<<-1<<"\n";continue;}
while(r>l)
{
    int mid=(l+r)/2;
    if(go(mid))r=mid;
    else l=mid+1;

}

cout<<l<<"\n";
    }
    return 0;
}