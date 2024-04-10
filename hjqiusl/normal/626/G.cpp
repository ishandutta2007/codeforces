//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define F(i,a,b) for (int i=(a);i<=(b);i++)
#define R(i,a,b) for (int i=(a);i<(b);i++)
#define D(i,a,b) for (int i=(a);i>=(b);i--)
#define go(i,x) for (int i=head[x];i;i=e[i].nx)
#define mp make_pair
#define pb push_back
#define pa pair < double,int >
#define fi first
#define se second
#define re register
#define be begin()
#define en end()
#define sqr(x) ((x)*(x))
#define ret return puts("-1"),0;
#define put putchar('\n')
#define inf 1000000005
#define mod 998244353
#define int ll
#define N 200005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
double ans;
int n,m,Q,a[N],p[N],l[N],x;
set<pa>S,S1;
inline double ad(int i)
{
	return 1.0*p[i]*min(1.0*(a[i]+1)/(l[i]+a[i]+1),0.5)-1.0*p[i]*min(1.0*(a[i])/(l[i]+a[i]),0.5);
}
inline double er(int i)
{
	return 1.0*p[i]*min(1.0*(a[i])/(l[i]+a[i]),0.5)-1.0*p[i]*min(1.0*(a[i]-1)/(l[i]+a[i]-1),0.5);
}
signed main()
{
	m=read(), n=read(),Q=read();
	for (int i=1;i<=m;i++) p[i]=read();
	for (int i=1;i<=m;i++) l[i]=read();
	for (int i=1;i<=m;i++)
	{
		S.insert(make_pair(ad(i),i));
		if (a[i]-1>=0) S1.insert(mp(er(i),i));
	}
	while (n--)
	{
		int i=(*S.rbegin()).se;
		ans+=(*S.rbegin()).fi;
		S.erase(mp(ad(i),i));
		if (a[i]-1>=0) S1.erase(mp(er(i),i));
		a[i]++;
		S.insert(mp(ad(i),i));
		if (a[i]-1>=0) S1.insert(mp(er(i),i));
	}	
	while (Q--)
	{
		x=read();
		int i=read();
		S.erase(mp(ad(i),i));
		if (a[i]-1>=0) S1.erase(mp(er(i),i));
		ans-=1.0*p[i]*min(1.0*(a[i])/(l[i]+a[i]),0.5);
		if (x==1) l[i]++; else l[i]--;
		ans+=1.0*p[i]*min(1.0*(a[i])/(l[i]+a[i]),0.5);
		S.insert(mp(ad(i),i));
		if (a[i]-1>=0) S1.insert(mp(er(i),i));
		while ((!S.empty()&&!S1.empty()))
		{
			if ((*S.rbegin()).fi-(*S1.begin()).fi>0)
			{
				int x=(*S.rbegin()).se,y=(*S1.begin()).se;
				ans+=(*S.rbegin()).fi-(*S1.begin()).fi;
				i=x;
				S.erase(mp(ad(i),i));
				if (a[i]-1>=0) S1.erase(mp(er(i),i));
				a[i]++;
				S.insert(mp(ad(i),i));
				if (a[i]-1>=0) S1.insert(mp(er(i),i));
				i=y;
				S.erase(mp(ad(i),i));
				if (a[i]-1>=0) S1.erase(mp(er(i),i));
				a[i]--;
				S.insert(mp(ad(i),i));
				if (a[i]-1>=0) S1.insert(mp(er(i),i));
			} else break;
		}
		printf("%.8lf\n",ans);
	}
					
		
}
/*
2 1 3
4 5
1 2
1 1
1 2
2 1
*/