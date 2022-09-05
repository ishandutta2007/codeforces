//by kcz 1552920354@qq.com
//if you find any bug in my code
//please tell me
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
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned short us;
typedef unsigned int ui;
typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
#define mp make_pair
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
const int N=100000+5;
pii q[2][N];int c[2];
void write(int i,int j)
{
	for(;j;--j)printf("%d ",q[i][j].second);
}
int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	int n=read(),v=read();
	rep(i,1,n)
	{
		int t=read(),p=read();
		q[t-1][++c[t-1]]=mp(p,i);
	}
	rep(i,0,1)sort(q[i]+1,q[i]+c[i]+1,greater<pii>());
	rep(i,0,1)
	rep(j,1,c[i])q[i][j].first+=q[i][j-1].first;
	pii ans=mp(-1,-1);
	rep(i,0,min(c[1],v/2))
	{
		chmax(ans,mp(q[1][i].first+q[0][min(c[0],v-2*i)].first,i));
	}
	printf("%d\n",ans.first);
	int i=ans.second;
	write(1,i);write(0,min(c[0],v-2*i));
}