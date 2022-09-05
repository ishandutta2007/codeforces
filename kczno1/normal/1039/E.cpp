#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmin(T &x,const T &y)
{
	if(x>y)x=y;
}
template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
const int N=1e5+5,L=50,LO=17;
int n,w,m,a[N];
int f_mn[LO][N],f_mx[LO][N],lo[N];
int to[N],lk[N],nmn[N],nmx[N];
int bl[N],br[N];
pii query[N];

priority_queue<pii,vector<pii>,greater<pii> >heap;
void push(int i)
{
	if(lk[i]<=br[i])heap.push(pii(nmx[i]-nmn[i],i));
}
void init()
{
	rep(i,2,n)lo[i]=lo[i/2]+1;
	rep(i,1,n)f_mn[0][i]=f_mx[0][i]=a[i];
	rep(j,1,lo[n])
	rep(i,1,n-(1<<j)+1)
	{
		f_mn[j][i]=min(f_mn[j-1][i],f_mn[j-1][i+(1<<j-1)]);
		f_mx[j][i]=max(f_mx[j-1][i],f_mx[j-1][i+(1<<j-1)]);
	}
	
	a[n+1]=-(1e9+5);
	rep(i,1,n)
	{
		int b=(i-1)/L;
		bl[i]=b*L+1;
		br[i]=min(n,(b+1)*L);
	}
	per(i,n,1)
	{
		lk[i]=i+1;nmn[i]=min(a[i],a[i+1]);nmx[i]=max(a[i],a[i+1]);
		to[i]=(lk[i]>br[i])?(i*64):(to[lk[i]]+1); 
		push(i);
	}
}
int solve(int k)
{
	while(!heap.empty()&&heap.top().first<=k)
	{
		int i=heap.top().second;heap.pop();
		++lk[i];
		chmin(nmn[i],a[lk[i]]);
		chmax(nmx[i],a[lk[i]]);
		per(j,i,bl[i])to[j]=(lk[j]>br[j])?(j*64):(to[lk[j]]+1); 
		push(i);
	}
	int i=1,ans=0;
	while(i<=n)
	{
		ans+=(to[i]&63)+1;
		i=to[i]/64;
		while(lk[i]<=i+1000&&nmx[i]-nmn[i]<=k)
		{
			++lk[i];
			chmin(nmn[i],a[lk[i]]);
			chmax(nmx[i],a[lk[i]]);
		}
		if(nmx[i]-nmn[i]>k)i=lk[i];
		else
		{
			per(j,lo[n-lk[i]+1],0)
			if(lk[i]+(1<<j)<=n&&max(nmx[i],f_mx[j][lk[i]+1])-min(nmn[i],f_mn[j][lk[i]+1])<=k)
			{
				chmax(nmx[i],f_mx[j][lk[i]+1]);
				chmin(nmn[i],f_mn[j][lk[i]+1]);
				lk[i]+=1<<j;
			}
			++lk[i];
			chmin(nmn[i],a[lk[i]]);
			chmax(nmx[i],a[lk[i]]);
			i=lk[i];
		}
	}
	return ans;
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif	
	cin>>n>>w>>m;
	rep(i,1,n)scanf("%d",a+i);
	init();
	rep(i,1,m)
	{
		int k;
		scanf("%d",&k);
		query[i]=pii(w-k,i);
	}
	sort(query+1,query+m+1);
	rep(i,1,m)query[i].first=solve(query[i].first);
	sort(query+1,query+m+1,[&](pii a,pii b){return a.second<b.second;});
	rep(i,1,m)printf("%d\n",query[i].first-1);
}