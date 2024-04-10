//~~
#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
//#define N
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,a,b,c,p,q;
struct node
{
	int cntu,cntr,sum;
	node()
	{
		cntu=0,cntr=0,sum=0;
	}
};
node operator *(node x,node y)
{
	y.sum+=x.sum+x.cntu*y.cntr;
	y.cntr+=x.cntr;
	y.cntu+=x.cntu;
	return y;
}
node quickPower(node x,int y)
{
	node res=node();
	while (y>0)
	{
		if (y&1) res=res*x;
		x=x*x;
		y>>=1;
	}
	return res;
}
node solve(int p,int q,int r,int l,node U,node R)
{
	// cout<<p<<" "<<q<<" "<<r<<" "<<l<<" "<<U.sum<<" "<<R.sum<<endl;
	if (!l) return node();
	if (p>=q) return solve(p%q,q,r,l,U,quickPower(U,p/q)*R);
	int cntu=(p*l+r)/q;
	// cout<<"!"<<(quickPower(R,l)).cntr<<endl;
	if (!cntu) return quickPower(R,l);
	int res=l-(q*cntu-r-1)/p;
	// cout<<res<<" "<<(q-r-1)/p<<" "<<(quickPower(R,(q-r-1)/p)*U).cntu<<endl;
	return quickPower(R,(q-r-1)/p)*U*solve(q,p,(q-r-1)%p,cntu-1,R,U)*quickPower(R,res);
}
int gtans(int n,int a,int b,int c)
{
 	node x;
 	x.cntu=1;
 	node y;
 	y.cntr=1;
 	node ans=quickPower(x,b/c)*solve(a,c,b%c,n,x,y);
 	ans.sum=(ans.sum+b/c);
 	return ans.sum;
}
void exgcd(int a,int b,int &x,int &y)
{
	if (b==0)
	{
		x=1,y=0;
		return;
	}
	exgcd(b,a%b,y,x);
	y-=((a/b))*x;
}
void BellaKira()
{
	a=read(),b=read(),p=read(),q=read();
	int l=0,r=q;
	int ans=0;
	while (l<=r)
	{
		int mid=l+(r-l)/2;
		int L=q-mid,R=q+mid;
		// cout<<"??"<<mid<<" "<<gtans(b,2*p,(2*q)-L,2*q)-gtans(a-1,2*p,(2*q)-L,2*q)-
		// (gtans(b,2*p,(2*q)-R-1,2*q)-gtans(a-1,2*p,(2*q)-R-1,2*q))<<endl;
		if (gtans(b,2*p,(2*q)-L,2*q)-gtans(a-1,2*p,(2*q)-L,2*q)-
		(gtans(b,2*p,(2*q)-R-1,2*q)-gtans(a-1,2*p,(2*q)-R-1,2*q))>0)
		{
			ans=mid;
			r=mid-1;
		} else l=mid+1;
	}
	int x,y;
	int A=2*p,B=(2*q);
	exgcd(A,B,x,y);
	// cout<<A<<" "<<B<<" "<<x<<" "<<y<<" "<<B/(__gcd(A,B))<<endl;
	int ansx=0;
	if ((q+ans)%__gcd(A,B)==0)
	{
		x=x*(q+ans)/__gcd(A,B);
		y=y*(q+ans)/__gcd(A,B);
		if (x>a)
		{
			int dis=x-a;
			x-=dis/(B/__gcd(A,B))*(B/__gcd(A,B));
			// x-=(B/__gcd(A,B));
		} else
		if (x<a)
		{
			int dis=a-x;
			x+=dis/(B/__gcd(A,B))*(B/__gcd(A,B));
			if (x<a) x+=(B/__gcd(A,B));
		}
		ansx=x;
	}
	exgcd(A,B,x,y);
	if ((q-ans)%__gcd(A,B)==0)
	{
		x=x*(q-ans)/__gcd(A,B);
		y=y*(q-ans)/__gcd(A,B);
		if (x>a)
		{
			int dis=x-a;
			x-=dis/(B/__gcd(A,B))*(B/__gcd(A,B));
			// x-=(B/__gcd(A,B));
		} else
		if (x<a)
		{
			int dis=a-x;
			x+=dis/(B/__gcd(A,B))*(B/__gcd(A,B));
			if (x<a) x+=(B/__gcd(A,B));
		}
		ansx=min(ansx,x);
	}
	writeln(ansx);
}
signed main()
{
	int T=read();
	// T=1;
	while (T--)
	{
		BellaKira();
	}
}
/*

*/