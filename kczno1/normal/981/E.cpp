#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
const int N=1e4+5;
int mx[N];
vector<pii>lk[N];
bool ans[N];

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif	
	int n,m;
	cin>>n>>m;
	rep(i,1,m)
	{
		int l,r,x;
		scanf("%d%d%d",&l,&r,&x);
		lk[l].push_back({r,x});
	}
	mx[0]=n;
	rep(i,1,n)
	{
		for(auto pr:lk[i])
		{
			int r=pr.first,x=pr.second;
			per(j,n,x)chmax(mx[j],min(mx[j-x],r));
		}
		rep(j,1,n)ans[j]|=mx[j]>=i;
	}
	int k=0;
	rep(i,1,n)k+=ans[i];
	printf("%d\n",k);
	rep(i,1,n)
	if(ans[i])printf("%d ",i);
}