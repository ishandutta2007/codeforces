#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
#define SZ(A) ((int)A.size())
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=1e6+20;

int a[maxn],b[maxn];
int mn[maxn];

int main()
{
	int n=read(),ans=2*n;
	REP(i,1,n)a[i]=read();
	REP(i,1,n)b[i]=read();

	REP(i,1,n)if(b[i])mn[b[i]]=i;
	
	int len=b[n],ok=1;
	DREP(i,len,1)if(b[n-i+1]!=len-i+1){ ok=0; break;}

	if(ok)
	{
		int gg=0;
		REP(i,len+1,n)if(mn[i]<i-len);
		else { gg=1;break;}
		if(!gg)chkmin(ans,n-len);
	}

	int mx=0;
	REP(i,1,n)chkmax(mx,mn[i]-i+1+n);
	chkmin(ans,mx);
	printf("%d\n",ans);
	return 0;
}