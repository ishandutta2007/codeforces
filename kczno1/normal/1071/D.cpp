#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmin(T &x,const T &y)
{
	if(x>y)x=y;
}
#define rep(i,l,r) for(int i=l;i<=r;++i)
const int pr[]={2,3,5,7,11,13,17};
const int N=1e6+5,S=300,T=920;
int dy[N],dys[N],dyt[N],scnt,tcnt,dis[S][T];
int r[N];
int mxt;
void dfs(int h,int d,int s,int t,int ms,int mt)
{
	if(!dys[s])dys[s]=++scnt;
	if(!dyt[t])dyt[t]=++tcnt;
	mxt=max(t,mxt);
	if(h==7)
	{
		chmin(dis[dys[s]][dyt[t]],d);
		return ;
	}
	for(int i=0;s<=1000000&&i<=ms;++i,s*=pr[h])
	for(int j=0;j<=mt;++j)
	if(d+abs(i-j)<=10)
		dfs(h+1,d+abs(i-j),s,t*(j+1),i,j);
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif
	rep(i,0,S-1)
	rep(j,0,T-1)dis[i][j]=100;
	dfs(0,0,1,1,100,100);
	cerr<<scnt<<" "<<tcnt<<" "<<mxt<<endl;	
	rep(i,1,1e6)
	{
		if(i>1&&!r[i])for(int j=i;j<=1e6;j+=i)r[j]=i;
		vector<int>a;
		int x=i;
		while(x>1)
		{
			int p=r[x],e=0;
			while(x%p==0){x/=p;++e;}
			a.push_back(e);
		}
		sort(a.begin(),a.end(),greater<int>());
		int ans=1;
		rep(i,0,int(a.size())-1)
		rep(j,1,a[i])ans*=pr[i];
		dy[i]=dys[ans];
	}
	int m;
	cin>>m;
	while(m--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		int ans=100;
		rep(i,1,tcnt)chmin(ans,dis[dy[a]][i]+dis[dy[b]][i]);
		printf("%d\n",ans);
	}
}