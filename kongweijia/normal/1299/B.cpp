#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100000
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

struct P
{
	int x,y;
	P(){}
	P(int x,int y):x(x),y(y){}
	void in() {scanf("%d%d",&x,&y);}
	P operator -(const P &a) const {return P(x-a.x,y-a.y);}
	ll len2() {return 1ll*x*x+1ll*y*y;}
}p[maxn+5];

ll dot(P a,P b) {return 1ll*a.x*b.x+1ll*a.y*b.y;}
ll cross(P a,P b) {return 1ll*a.x*b.y-1ll*a.y*b.x;}

bool check(int n)
{
	p[n]=p[0];
	if(n&1) return 0;
	int m=n/2;
	rep(i,0,m-1) if(!(cross(p[i+1]-p[i],p[i+m+1]-p[i+m])==0 && dot(p[i+1]-p[i],p[i+m+1]-p[i+m])<0 && (p[i+1]-p[i]).len2()==(p[i+m+1]-p[i+m]).len2())) return 0;
	return 1;
}

int main()
{
	int n; scanf("%d",&n);
	rep(i,0,n-1) p[i].in();
	puts(check(n)?"YES":"NO");
	return 0;
}