#include<bits/stdc++.h>
#define REP(i,a,b) for(int i(a);i<=(b);++i)
using namespace std;
typedef long long ll;
template<typename T>
inline void read(T&w){char c,p=0;
	while(!isdigit(c=getchar()))if(c=='-')p=1;w=c^'0';
	while(isdigit(c=getchar()))w=w*10+(c^'0');if(p)w=-w;
}
template<typename T,typename U>inline char smax(T&x,const U&y){return x<y?x=y,1:0;}
template<typename T,typename U>inline char smin(T&x,const U&y){return x>y?x=y,1:0;}
const int N=755,M=2e5+5;
int n,m,a[N],t,p1[N],p2[M],ans[M];
ll f[N][N],b[M],s[N];
//priority_queue<int>q;
inline bool cmp1(int i,int j){return f[1][i]>f[1][j];}
inline bool cmp2(int i,int j){return b[i]<b[j];}
int main(){
	read(n),read(m);
	REP(i,1,n)if((read(a[i]),s[i]=s[i-1]+a[i],a[i])<=0)++t;
//	memset(f,0x3f,sizeof f);
	f[n][0]=s[n],f[n][1]=s[n-1];
	for(int i=n-1;i;--i){
		int r=min(t,n-i+1);
		f[i][0]=min(f[i+1][0],s[i]);//cout<<"f!   "<<f[i][0]<<' ';
		REP(j,1,r)f[i][j]=f[i+1][j-1]-a[i],j<=n-i&&smax(f[i][j],min(f[i+1][j],s[i]));
	//	cout<<endl;
	}
	REP(i,0,t)p1[i]=i;
	sort(p1,p1+1+t,cmp1);
	REP(i,1,m)read(b[i]),p2[i]=i;
	sort(p2+1,p2+1+m,cmp2);
	int now=t+1,l=0;
	REP(i,1,m){
		int&x=p2[i];
		while(l<=t&&b[x]+f[1][p1[l]]>=0)smin(now,p1[l++]);
		ans[x]=now;
	}
	REP(i,1,m)printf("%d\n",ans[i]);
	return 0;
}