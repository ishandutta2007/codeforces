#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=(a);i<=(n);i++)
#define per(i,a,n) for(int i=(n);i>=(a);i--)
#define infty 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define xx first
#define yy second
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> PII;
typedef vector<int> VI;
//head

const int maxn=400000;

int a[maxn+5];
int V[maxn+5];
int n;

int ans;

void solve(int b)
{
	int l=b+1;
	int BASE=(1<<l)-1;
	rep(i,1,n)
	{
		V[i]=a[i]&BASE;
	}
	sort(V+1,V+n+1);
	ll cnt=0;
	rep(i,1,n)
	{
		int x=V[i],tmp=0;
		tmp+=upper_bound(V+1,V+n+1,(1<<l)-1-x)-V - (upper_bound(V+1,V+n+1,(1<<(l-1))-1-x)-V);
		tmp+=upper_bound(V+1,V+n+1,(1<<(l+1))-2-x)-V - (upper_bound(V+1,V+n+1,(1<<(l-1))+(1<<l)-1-x)-V);
		if(((x*2)>>b)&1) tmp--;
		cnt+=tmp;
		//printf("?? %d: %d, %d\n",b,x,tmp);
	}
	assert(cnt%2==0);
	cnt/=2;
	ans+=(cnt&1)<<b;
}

int main()
{
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	rep(b,0,24) solve(b);
	printf("%d\n",ans);
	return 0;
}