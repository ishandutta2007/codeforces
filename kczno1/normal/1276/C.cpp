#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmin(T&x,const T &y)
{
	if(x>y)x=y;
}
template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
typedef int64_t s64;
typedef uint64_t u64;
typedef uint32_t u32;
typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define rep0(i,l,r) for(int i=l;i<r;++i)
#define gc (c=getchar())
int read()
{
	char c;
	while(gc<'-');
	if(c=='-')
	{
		int x=gc-'0';
		while(gc>='0')x=x*10+c-'0';
		return -x;
	}
	int x=c-'0';
	while(gc>='0')x=x*10+c-'0';
	return x;
}
#undef gc

const int N=4e5+5;
int a[N],q[N],u;
vector<int>lk[N];
int c[N];
vector<int>Map[N];int h[N];

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n=read();
	rep(i,1,n)q[i]=a[i]=read();
	sort(q+1,q+n+1);
	int u=unique(q+1,q+n+1)-q-1;
	rep(i,1,n)lk[lower_bound(q+1,q+u+1,a[i])-q].push_back(a[i]);
	rep(i,1,u)++c[lk[i].size()];
	per(i,n,1)c[i]+=c[i+1];
	int sum=0;int ans=0,mA=0;
	rep(A,1,n)
	{
		sum+=c[A];
		if(sum/A>=A&&A*(sum/A)>ans){ans=A*(sum/A);mA=A;}
	}
	printf("%d\n",ans);
	int mB=ans/mA;
	printf("%d %d\n",mA,mB);
	rep(i,0,mA-1){Map[i].resize(mB);h[i]=i;}
	rep(i,1,u)q[i]=i;
	sort(q+1,q+u+1,[&](int x,int y){return lk[x].size()>lk[y].size();});
	int ni=0;
	rep(hi,1,u){int i=q[hi];
	rep(j,0,min((int)lk[i].size(),mA)-1)
	{
		if((ans--)<=0)break;
		//cerr<<i<<" "<<j<<" "<<ni<<" "<<h[ni]<<endl;
		Map[ni][h[ni]]=lk[i][j];
		(++h[ni])%=mB;
		(++ni)%=mA;
	}}
	//cerr<<ans<<endl;
	rep(i,0,mA-1)
	rep(j,0,mB-1)printf("%d%c",Map[i][j]," \n"[j==mB-1]);
}