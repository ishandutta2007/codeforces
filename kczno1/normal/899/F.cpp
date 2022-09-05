
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define rep(i,l,r) for(int i=l;i<=r;++i)

const int N=2e5+5,T=N*4;
ull have[T];
int sz[T];
int dy[256];
map<ull,char>ndy;

ull read()
{
	char c;
	while(c=getchar(),c<'0');
	return 1LL<<dy[c];
}

void get_dy()
{
	int tot=0;
	rep(i,'a','z')
	{
		ndy[1LL<<tot]=i;
		dy[i]=tot++;
	}
	rep(i,'A','Z')
	{
		ndy[1LL<<tot]=i;
		dy[i]=tot++;
	}
	rep(i,'0','9')
	{
		ndy[1LL<<tot]=i;
		dy[i]=tot++;
	}
}
#define cl (k*2)
#define cr (cl+1)
#define mid (l+r>>1)
void up(int k)
{
	sz[k]=sz[cl]+sz[cr];have[k]=have[cl]|have[cr];
}
void init(int k,int l,int r)
{
	if(l==r)
	{
		have[k]=read();
		sz[k]=1;
		return ;
	}
	init(cl,l,mid);init(cr,mid+1,r);
	up(k);
}
ull now;
void dfs(int k,int ql,int qr)
{
	if(!(have[k]&now))return ;
	if(sz[k]==1)
	{
		sz[k]=0;have[k]=0;
		return ;
	}
	if(qr>sz[cl]) dfs(cr,ql-sz[cl],qr-sz[cl]);
	if(ql<=sz[cl]) dfs(cl,ql,qr);
	up(k);
}

void out(int k)
{
	if(!sz[k]) return ;
	if(sz[k]==1)
	{
		putchar(ndy[have[k]]);
		return ;
	}
	out(cl);out(cr);
}

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	get_dy();
	int n,m;
	cin>>n>>m;
	init(1,1,n);
	while(m--)
	{
		int ql,qr;
		scanf("%d%d",&ql,&qr);
		now=read();
		dfs(1,ql,qr);
	//	out(1);	puts("");
	}
	out(1);	
}