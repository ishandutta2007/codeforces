#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 2000005
#define inf 2e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

ll y[maxn];

int main()
{
	//freopen("t1.in","r",stdin);
	ll a,b,c; cin>>a>>b>>c;
	ll x=inf,tmp;
	puts("First"); fflush(stdout); cout<<x<<endl; fflush(stdout);
	cin>>tmp;
	if(tmp==1) a+=x;
	else if(tmp==2) b+=x;
	else c+=x;
	y[1]=a; y[2]=b; y[3]=c; sort(y+1,y+3+1);
	ll x1=y[2]-y[1],x2=y[3]-y[2],q=x1+2*x2;
	cout<<x1+2*x2<<endl; fflush(stdout);
	cin>>tmp;
	if(tmp==1) a+=q;
	else if(tmp==2) b+=q;
	else c+=x;
	y[1]=a; y[2]=b; y[3]=c; sort(y+1,y+3+1);
	cout<<y[2]-y[1]<<endl; cin>>x;
	return 0;
}