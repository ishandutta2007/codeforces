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
inline void myassert(bool a,string s){ if(!a)cerr<<s<<endl,exit(0);}
inline int read()
{
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return ~f?s:-s;
}

inline unsigned power(unsigned a,unsigned b)
{
	unsigned int ans=1;
	while(b)
	{
		if(b&1)ans=ans*a;
		b>>=1;
		a=a*a;
	}
	return ans;
}

int n,m,q;
unsigned int ans;

inline void init()
{
	n=read();m=read();q=read();
	chkmin(m,n-1);
}

unsigned C[200];

inline void doing()
{
	int num2=0; unsigned res=1;
	function<void(int x,int op)>deal=[&](int x,int op){
		while(~x&1)x>>=1,num2+=op;
		if(op==1)res=res*x;
		else res=res*power(x,(1u<<31)-1);
	};
	function<unsigned int()>VAL=[&]() {
		return res<<num2;
	};
	C[0]=1;
	REP(i,1,m)
	{
		deal(n-i+1,1);
		deal(i,-1);
		C[i]=VAL();
	}
	unsigned Ans=0;
	REP(i,1,q)
	{
		unsigned res=0,prod=1;
		REP(j,0,m)res+=C[j]*prod,prod*=i;
		Ans^=res*i;
	}
	printf("%u",Ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("351F.in","r",stdin);
	freopen("351F.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}