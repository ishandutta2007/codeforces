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

int n,k;
int a[maxn];

int main()
{
    int t=read();
    while(t--)
    {
	n=read();k=read();
	REP(i,1,n)a[i]=read(),a[i]=(a[i]>k)+(a[i]>=k);
	int ok=0,gg=1;
	REP(i,1,n)if(a[i]==1)gg=0;
	if(gg==1){ puts("no"); continue;}

	if(n==1) ok=1;
	if(n==2) ok=a[1]!=0 && a[2]!=0;
	
	REP(i,1,n-1)if(a[i]>=1 && a[i+1]>=1)ok=1;
	REP(i,2,n-1)if(a[i-1]>=1 && a[i]==0 && a[i+1]>=1)ok=1;
	if(ok)puts("yes");
	else puts("no");
    }
    return 0;
}