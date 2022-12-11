#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define ll unsigned long long
#define RG register
#define REP(i,a,b) for(RG int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(RG int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

#define int unsigned int

const int maxn=2e5+20;
const int inv3=2863311531;

int prime[maxn],tot,mark[maxn];

int n,rk[maxn],A,B,C,D;
int S,id[maxn],ct;

int a[maxn],b[maxn],c[maxn],d[maxn];
int f[maxn];

inline void init()
{
	cin>>n;S=sqrt(n);
	A=read();B=read();C=read();D=read();
	REP(i,2,S)
	{
		if(!mark[i])prime[++tot]=i;
		for(int j=1;j<=tot && i*prime[j]<=S;j++)
		{
			int k=i*prime[j];
			mark[k]=1;
			if(!(i%prime[j]))break;
		}
	}
	REP(i,1,S)b[i]=(int)((ll)i*(i+1)/2*(2*i+1)*inv3),c[i]=(int)((ll)i*(i+1)/2),d[i]=i,a[i]=c[i]*c[i],rk[++ct]=i;
	DREP(i,S-(n/S==S),1)rk[++ct]=n/i,id[i]=ct,b[ct]=(ll)rk[ct]*(rk[ct]+1)/2*(2*rk[ct]+1)*inv3,c[ct]=(ll)rk[ct]*(rk[ct]+1)/2,d[ct]=rk[ct],a[ct]=c[ct]*c[ct];
	REP(i,1,ct)a[i]--,b[i]--,c[i]--,d[i]--;
	
	REP(i,1,tot)
	{
		DREP(j,ct,1)if((ll)prime[i]*prime[i]<=rk[j])
		{
			ll k=rk[j]/prime[i];
			k=k<=S?k:id[n/k];
			//g[j]=(g[j]-(ll)prime[i]*(g[k]-g[prime[i]-1])%mod+mod)%mod;
			//s[j]=(s[j]-(s[k]-s[prime[i]-1]))%mod;if(s[j]<0)s[j]+=mod;
			a[j]-=prime[i]*prime[i]*prime[i]*(a[k]-a[prime[i]-1]);
			b[j]-=prime[i]*prime[i]*(b[k]-b[prime[i]-1]);
			c[j]-=prime[i]*(c[k]-c[prime[i]-1]);
			d[j]-=(d[k]-d[prime[i]-1]);
		}else break;
	}
	REP(i,1,ct)f[i]=a[i]*A+b[i]*B+c[i]*C+d[i]*D;
}

#define pri pair<int,int>
#define mkr(a,b) make_pair(a,b)
#define fi first
#define se second

inline int FF(int x){ return A*x*x*x+B*x*x+C*x+D;}

pri F(int x,int y)
{
	if(x<prime[y] || x<1)return mkr(0,0);
	int a1=f[x]-f[prime[y-1]],a4=d[x]-d[prime[y-1]];
	REP(i,y,tot)if((ll)prime[i]*prime[i]<=rk[x])
	{
		int st=prime[i];int l=1;
		while((ll)st*prime[i]<=rk[x])
		{
			int t=rk[x]/st;
			t=t<=S?t:id[n/t];
			pri x=F(t,i+1);
			a1+=x.se*l*FF(prime[i]);//pls(ans,(ll)F(t,i+1)*(prime[i]^l)%mod);
			a1+=x.fi;
			a4+=x.se;
			a1+=(l+1)*FF(prime[i]);
			a4++;
			
			st*=prime[i];l++;
		}
		//if(ans>=(ll)mod*1000000)ans-=(ll)mod*1000000;
	}else break;
	return mkr(a1,a4);
}

inline void doing()
{
	cout<<F(ct,1).fi<<endl;
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("F.in","r",stdin);
	freopen("F.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}