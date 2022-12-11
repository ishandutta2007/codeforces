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
inline ll read()
{
	ll s=0;int f=1;char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return ~f?s:-s;
}
inline void myassert(bool a,string s){ if(!a)cerr<<s<<endl,exit(0);}

const int maxn=1e5+20;

int n;

ll A[maxn][5];

inline void init()
{
	n=read();
	REP(i,1,n)
	{
		ll x=read(),y=read(),z=read();
		A[i][1]=x+y+z; A[i][2]=x+y-z;
		A[i][3]=x-y+z; A[i][4]=x-y-z;
	}
}

ll Ans[4];

inline bool check(ll mid)
{
	ll L[5],R[5];
	REP(i,1,4)L[i]=A[1][i]-mid,R[i]=A[1][i]+mid;
	REP(j,2,n)
	{
		REP(i,1,4)
		{
			chkmax(L[i],A[j][i]-mid); chkmin(R[i],A[j][i]+mid);
		}
	}
	ll LL[5],RR[5],B[5];
	for(int op=0;op<2;op++)
	{
		int ok=1;
		REP(i,1,4)
		{
			LL[i]=L[i],RR[i]=R[i];
			if(LL[i]+op&1)LL[i]++;
			if(RR[i]+op&1)RR[i]--;
			if(LL[i]>RR[i])ok=0;
		}
		chkmax(LL[4],LL[2]+LL[3]-RR[1]);
		chkmin(RR[4],RR[2]+RR[3]-LL[1]);
		if(LL[4]>RR[4])ok=0;
		if(!ok)continue;

		B[2]=LL[2]; B[3]=LL[3];
		B[1]=RR[1]; B[4]=LL[2]+LL[3]-RR[1];
		ll cha=LL[4]-B[4];
		if(cha>0)
		{
			if(RR[1]-LL[1]>=cha)B[1]-=cha;
			else {
				B[1]=LL[1],cha-=RR[1]-LL[1];
				if(RR[2]-LL[2]>=cha)B[2]+=cha;
				else {
					B[2]=RR[2],cha-=RR[2]-LL[2];
					B[3]+=cha;
				}
			}
		}
		B[4]=B[2]+B[3]-B[1];
		myassert(LL[4]<=B[4] && B[4]<=RR[4],"fake at 85");
		
		{
			Ans[1]=B[2]+B[3]>>1; //myassert(~B[1]+B[2]&1,"x no even");
			Ans[2]=B[1]-B[3]>>1; //myassert(~B[1]-B[3]&1,"y no even");
			Ans[3]=B[1]-B[2]>>1; //myassert(~B[1]-B[2]&1,"z no even");
			return 1;
		}
	}
	return 0;
}

inline void doing()
{
	ll l=0,r=4e18;
	while(l<r)
	{
		ll mid=l+(r-l>>1);
		if(check(mid))r=mid;
		else l=mid+1;
	}
	REP(i,1,3)printf("%lld ",Ans[i]); puts("");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("CF685C.in","r",stdin);
	freopen("CF685C.out","w",stdout);
#endif
	int t=read();
	while(t--)
	{
		init();
		doing();
	}
	return 0;
}