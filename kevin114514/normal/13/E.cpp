#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC target("avx","sse2")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define lb(v,x) (lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (upper_bound(ALL(v),x)-v.begin())
void die(string S){puts(S.c_str());exit(0);}
int nom[114514],lib[114514];
int a[114514];
const int B=320;
int id(int x)
{
	return x/B;
}
int n,q;
inline void refresh(int bl)
{
	const int x1=bl*B+B,x2=bl*B;
	for(int i=min(x1-1,n);i>=x2;i--)
		if(i+a[i]>=x1)
		{
			nom[i]=1;
			lib[i]=i;
		}
		else
		{
			nom[i]=nom[i+a[i]]+1;
			lib[i]=lib[i+a[i]];
		}
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	const int dest=B*(id(n)+1);
	for(int i=1;i<=n;i++)
		if(i+a[i]>n)
			a[i]=dest-i;
	for(int i=0;i<=id(n);i++)
		refresh(i);
	while(q--)
	{
		int type;
		scanf("%d",&type);
		if(type)
		{
			int x;
			scanf("%d",&x);
			int noma=0,liba=0;
			while(x<=n)
			{
				noma+=nom[x];
				liba=lib[x];
				x=lib[x];
				x+=a[x];
			}
			printf("%d %d\n",liba,noma);
		}
		else
		{
			int p,v;
			scanf("%d%d",&p,&v);
			a[p]=v;
			if(p+a[p]>n)
				a[p]=dest-p;
			refresh(id(p));
		}
	}
	return 0;
}