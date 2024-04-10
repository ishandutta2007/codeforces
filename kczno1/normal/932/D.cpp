
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
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
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
const int N=4e5+5,L=20;
int fa[N][L],mx[N][L];
int fa2[N][L];ll s[N][L];

int n=1;
void add(int x,int w)
{
	++n;
	fa[n][0]=x;
	mx[n][0]=w;
	for(int j=1;fa[n][j]=fa[fa[n][j-1]][j-1];++j)mx[n][j]=max(mx[n][j-1],mx[fa[n][j-1]][j-1]);
	int y=fa[n][0];
	for(int j=L-1;j>=0;--j)
	if(fa[y][j])
	if(mx[y][j]<w)y=fa[y][j];
	s[n][0]=w;
	if(mx[y][0]<w)return ;
	fa2[n][0]=y;
	for(int j=1;fa2[n][j]=fa2[fa2[n][j-1]][j-1];++j)s[n][j]=s[n][j-1]+s[fa2[n][j-1]][j-1];
}
int qiu(int x,ll l)
{
	int ans=0;
	for(int j=L-1;j>=0;--j)
	if(fa2[x][j])
	if(s[x][j]<=l)
	{
		l-=s[x][j];x=fa2[x][j];ans+=1<<j;
	}
	if(x&&s[x][0]<=l)++ans;
	return ans;
}

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	int tt;
	cin>>tt;
	int last=0;
	while(tt--)
	{
		int type;ll p,q;
		scanf("%d%I64d%I64d",&type,&p,&q);
		p^=last;q^=last;
		if(type==1)add(p,q);
		else printf("%d\n",last=qiu(p,q));
	}
}