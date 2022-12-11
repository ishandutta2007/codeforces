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

const int maxn=1e6+20;

char str[maxn<<1],T[maxn];
int n;

int p[maxn<<1];

ll Manacher(char *s)
{
	int len=n;
    s[len+len+2]='\n';s[len+len+1]='#';s[0]='-';
    for(int i=len;i;--i)
    {
        s[i*2]=s[i];
        s[i*2-1]='#';
    }
    int mx=0,id=0;
    for(int i=1;i<=len+len;++i)
    {
        p[i]=mx>i?min(p[id*2-i],mx-i):1;
        while(s[i+p[i]]==s[i-p[i]])++p[i];
        if(i+p[i]>mx)id=i,mx=p[i]+i;
    }
}

inline void doing()
{
	scanf("%s",str+1);
	n=strlen(str+1);
	REP(i,1,n)T[i]=str[i];
	Manacher(str);
	int LEN=0,LL=1,RR=0,id=LEN,ans=2*LEN;
	REP(i,1,n/2)if(T[i]==T[n-i+1])
	{
		LEN=i;
	}else break;
	REP(i,2,2*n)
	{
		int l=i-p[i]+2>>1,r=i+p[i]-2>>1;
		int re=min(l-1,n-r);
		if(re<=LEN && ans<re*2+r-l+1)
			ans=re*2+r-l+1,LL=l,RR=r,id=re;
	}
	REP(i,1,id)printf("%c",T[i]);
	REP(i,LL,RR)printf("%c",T[i]);
	REP(i,n-id+1,n)printf("%c",T[i]);
	puts("");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
#endif
	int t=read();
	while(t--)
	{
		doing();
	}
	return 0;
}