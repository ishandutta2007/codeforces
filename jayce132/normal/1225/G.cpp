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
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
inline int read()
{
	int s=0,f=1; char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return ~f?s:-s;
}

const int maxn=2000+20;

bitset<maxn>f[1<<16];
int n;
int a[maxn],k;

inline void init()
{
	n=read();k=read();
	REP(i,1,n)a[i]=read();
	f[0].set(0);
	REP(i,1,n)f[1<<i-1].set(a[i]);
}

#define pii pair<int,int>

inline void doing()
{
	REP(i,1,(1<<n)-1)
	{
		for(int j=2000/k*k;j;j-=k)
			if(f[i][j])
				f[i][j/k]=1;
		REP(x,1,n)if(~i>>x-1&1)
			f[i|(1<<x-1)]|=f[i]<<a[x];
	}
	int M=1<<n; M-=1;
	if(!f[M][1])puts("NO");
	else {
		puts("YES");
		multiset<pii>ANS;
		int tim=n,val=1,add=0;
		while(tim--)
		{
			//int tx=0,tval=0;
			int VAL=val,flg=0,tx=0;
			while(VAL<=2000)
			{
				REP(x,1,n)if(M>>x-1&1)
					if(a[x]<=VAL && f[M^(1<<x-1)][VAL-a[x]])
					{
						flg=1; tx=x;
						break;
					}
				if(flg){ break;}
				else VAL*=k,add++;
			}
			val=VAL-a[tx]; M^=1<<tx-1;
			ANS.insert(mkr(add,a[tx]));
		}
		while(SZ(ANS)>=2)
		{
			set<pii>::iterator a=ANS.end(),b;
			a--; b=a; b--;
			int cadd=a->fi,c=a->se+b->se;
			while(c%k==0)c/=k,cadd--;
			printf("%d %d\n",a->se,b->se);
			ANS.erase(a); ANS.erase(b);
			ANS.insert(mkr(cadd,c));
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1225G.in","r",stdin);
	freopen("1225G.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}