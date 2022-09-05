#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)

template <typename T> inline void chmin(T &x,const T &y)
{
	if(x>y)x=y;
}
template <typename T> inline void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}

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

const int N=2e5+5;
int n,m;
int fa[N];

int find(int x)
{
	if(!fa[x])return x;
	return fa[x]=find(fa[x]);
}

int main()
{
	//freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	cin>>n>>m;
	if(n!=m){puts("NO");exit(0);}
	bool huan=0;
	while(m--)
	{
		int x=find(read()),y=find(read());
		if(x==y)
		{
			if(huan){puts("NO");exit(0);}
			huan=1;
		}
		else
		{
			fa[x]=y;
		}
	}
	puts("FHTAGN!");
}