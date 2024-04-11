#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 1000000
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int a[maxn+5];
ll s[maxn+5];
struct P
{
	ll x,y;
	P(){}
	P(ll x,ll y):x(x),y(y){}
	P operator -(const P &a) const {return P(x-a.x,y-a.y);}
}p[maxn+5];
ll cross(P a,P b) {return a.x*b.y-a.y*b.x;}

P q[maxn+5];

int main()
{
	int n; scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	rep(i,1,n) s[i]=s[i-1]+a[i];
	rep(i,1,n) p[i]=P(i,s[i]);
	int rear=0;
	rep(i,1,n)
	{
		while(rear && cross(p[i]-q[rear],q[rear]-q[rear-1])>=0) rear--;
		q[++rear]=p[i];
	}
	rep(i,1,rear)
	{
		db x=(db)(q[i]-q[i-1]).y/(q[i]-q[i-1]).x;
		rep(j,1,(q[i]-q[i-1]).x) printf("%.15f\n",x);
	}
	return 0;
}