/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
using namespace std;

long long int gcd(long long int a,long long int b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}

void solve()
{
    long long int m,d,w,x,y;
    cin>>m>>d>>w;
    y=min(d,m);
    m=y;
    d--;
    x=gcd(d,w);
    w/=x;

    y--;
    long long int ans=0;
    y/=w;
    x=y;
    y=((y*(y+1))/2);
    y*=w;
    ans+=y;

    m--;
    m%=w;
    m=(w-1-m);
    m*=x;
    ans-=m;

    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin>>t;
	while(t--) solve();
	return 0;
}