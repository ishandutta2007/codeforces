#include<bits/stdc++.h>
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

int n,x,y;

inline int ASK(vector<int>ask)
{
	printf("? %d ",SZ(ask)); int should=SZ(ask)&1?x:0; 
	REP(i,0,SZ(ask)-1)printf("%d ",ask[i]); fflush(stdout);
	int t=read();
	return t!=should;
}

inline int solve(vector<int>now)
{
	if(SZ(now)==1)return now.front();
	vector<int>le,ri;
	REP(i,0,SZ(now)-1)if(i&1)le.push_back(now[i]); else ri.push_back(now[i]);
	if(ASK(le))return solve(le);
	else return solve(ri);
}

int main()
{
	n=read();x=read();y=read();
	int ti=-1,cha=0;
	REP(i,0,9)if((1<<i)<=n)
	{
		vector<int>ask;
		REP(j,1,n)if(j>>i&1)ask.push_back(j);
		int t=ASK(ask);
		cha|=t<<i;
		if(t==1){ ti=i;}
	}
	
	vector<int>now; REP(j,1,n)if(j>>ti&1)now.push_back(j);
	int ans=solve(now),a=ans,b=ans^cha;
	if(a>b)swap(a,b);
	printf("! %d %d\n",a,b); fflush(stdout);
	return 0;
}