#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,u) for(int i=start[u];i;i=e[i].next)
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
#define SZ(A) ((int)A.size())
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
inline int read()
{
	int s=0,f=1; char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return ~f?s:-s;
}

const int maxn=1e5+20;
const int inf=0x3f3f3f3f;

int n,m;
int a[maxn],b[maxn],tb;
int k,rk[maxn];
int put[maxn];

inline void init()
{
	n=read();
	REP(i,1,n)
	{
		a[i]=read();
		if(a[i]==-1)rk[++k]=a[i];
	}
	m=read();
	REP(i,1,m)b[i]=read();
	sort(b+1,b+m+1);
	tb=unique(b+1,b+m+1)-b-1;
}

#define pii pair<int,int>

#define real REAL

int f[maxn],pos[maxn],top;
int pre[maxn],len[maxn];
int real[maxn];

inline void doing()
{
	f[0]=0;
	memcpy(real,a,sizeof(int)*(n+1));
	REP(i,1,n)
	{
		if(~a[i])
		{
			/*function<void(int x)> Upper_bound =[&](int x) {
				int l=0,r=top+1;
				while(l<r)
				{
					int mid=l+r>>1;
					if(f[mid]>=x)r=mid;
					else l=mid+1;
				}
				chkmax(top,l);
				};*/
			//Upper_bound(x);
			int t=lower_bound(f+1,f+top+1,a[i])-f;
			if(t>top)++top;
			f[t]=a[i]; pos[t]=i;
			pre[i]=pos[t-1];
			len[i]=t;
		}else
		{
			int k=m;
			f[top+1]=inf;
			DREP(j,top+1,1)
			{
				while(k>1 && b[k-1]>f[j-1])--k;
				if(f[j-1]<b[k] && b[k]<f[j])f[j]=b[k],pos[j]=i;
			}
			if(f[top+1]!=inf)++top;
		}
	}
	int ans=top,lim=inf;
	int t=pos[top];
	while(t)
	{
		if(a[t]==-1)
		{
			vector<int>SBPOS;
			DREP(p,t,0)if(~a[p])
			{
				int cha=ans-len[p];
				if(a[p]<lim && SZ(SBPOS)>=cha && ((lower_bound(b+1,b+tb+1,lim)-1)-b)-(upper_bound(b+1,b+tb+1,a[p])-b)+1>=cha)
				{
					int st=upper_bound(b+1,b+tb+1,a[p])-b;
					REP(i,0,cha-1)real[SBPOS[cha-i-1]]=b[st+i],put[st+i]=1;
					t=p;
					ans=len[p];
					break;
				}
			}else SBPOS.push_back(p);
		}else --ans,lim=a[t],t=pre[t];
	}
	int k=0;
	REP(i,1,n)if(real[i]==-1)
	{
		++k;
		while(put[k])++k;
		real[i]=b[k];
	}
	REP(i,1,n)printf("%d ",real[i]);
}

int main()
{
#ifndef ONLINE_JUDGE	
	freopen("CF568E.in","r",stdin);
	freopen("CF568E.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}