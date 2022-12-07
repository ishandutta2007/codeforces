#include<cstdio>
#include<algorithm>
#include<map>
#include<cstring>
#include<vector>
#include<string>
#include<queue>
#define N 200010
#define M 1010
using namespace std;
typedef long long ll;
const ll INF = ~0ULL>>1;

priority_queue<ll,vector<ll>,greater<ll> > q;
int Q;
int ansx,ansy,ansid;
ll ans;

struct node{
	int d[2];
	int id;
	void setter(int x,int y,int z){d[0]=x;d[1]=y;id=z;}
	bool operator <(const node &b)const{return d[Q]<b.d[Q];}
}p[N];
struct kdtree{
	node val[N];
	int ls[N],rs[N],minv[N][2],maxv[N][2],root;

	//kdtree
	void updata(int x)
	{
		for (int i=0;i<=1;i++)
		{
			minv[x][i]=maxv[x][i]=val[x].d[i];
			if (ls[x])
			{
				minv[x][i]=min(minv[ls[x]][i],minv[x][i]);
				maxv[x][i]=max(maxv[ls[x]][i],maxv[x][i]);
			}
			if (rs[x])
			{
				minv[x][i]=min(minv[rs[x]][i],minv[x][i]);
				maxv[x][i]=max(maxv[rs[x]][i],maxv[x][i]);
			}
		}
	}
	int build(int l,int r,int k)
	{
		if (l>r) return 0;
		int m=(l+r)>>1;
		Q=k;
		nth_element(p+l,p+m,p+r+1);
		val[m]=p[m];
		ls[m]=build(l,m-1,k^1);
		rs[m]=build(m+1,r,k^1);
		updata(m);
		return m;
	}
	ll sqr(ll x)
	{
		return x*x;
	}
	ll get(node v,int x)
	{
		if (!x) return 0;
		ll ans=0;
		for (int i=0;i<=1;i++) {
			//    ans+=max(sqr(v.d[i]-minv[x][i]),sqr(v.d[i]-maxv[x][i]));
			if (v.d[i] <  minv[x][i]) ans += sqr(minv[x][i] - v.d[i]);
			if (maxv[x][i] < v.d[i]) ans += sqr(v.d[i] - maxv[x][i]);
		}
		return ans;
	}
	ll dist(node a,node b)
	{
		ll ans=0;
		for (int i=0;i<=1;i++)
			ans+=sqr(a.d[i]-b.d[i]);
		return ans;
	}
	void query(node v,int x)
	{
		ll lm=0,rm=0,dis;
		if (!x) return;
		lm=get(v,ls[x]);
		rm=get(v,rs[x]);

		if ((v.d[0]!=val[x].d[0])||(v.d[1]!=val[x].d[1]))
		{
			dis=dist(v,val[x]);
			if (dis < ans || (dis == ans && (val[x].d[0] < ansx || (val[x].d[0] == ansx && val[x].d[1] < ansy))))
			{
				ans = dis;
				ansx=val[x].d[0];
				ansy=val[x].d[1];
				ansid=val[x].id;
			}
		}
		if (lm<rm)
		{
			if (lm<=ans) query(v,ls[x]);
			if (rm<=ans) query(v,rs[x]);
		}
		else
		{
			if (rm<=ans) query(v,rs[x]);
			if (lm<=ans) query(v,ls[x]);
		}
	}

}KDT;

int n, a;

int main()
{
	scanf("%d",&n);
	int x, y;
	for (int i=1;i<=n;i++)
	{
		scanf("%d", &a);
		x = i, y += a;
		p[i].setter(x,y,i);
	}
	KDT.root=KDT.build(1,n,0);
	ll out = INF;
	for (int i=1;i<=n;i++)
	{
		ans=INF;ansid=0;
		KDT.query(p[i],KDT.root);
		out = min(out, ans);
	}
	printf("%lld\n", out);
	return 0;
}