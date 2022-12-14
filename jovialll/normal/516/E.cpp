#include<bits/stdc++.h>
using namespace std;
#define N 300005
#define ll long long
#define int long long
int t,aa,bb,n,m,l,A,B,e,a[N],b[N],tmp[N],f1,f2,G,k1,k2;
struct U{int num,F;}u[N];
ll res,x,ans;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
inline bool cmp(int x,int y){return x%G<y%G;}
inline bool Cmp(U x,U y){return x.F<y.F;}
inline void cal(int A,int B,int C){
	if(B==0){aa=C/A;bb=0;return;}
	cal(B,A%B,C);t=aa;aa=bb;bb=t-(A/B)*bb;
}void solve(int g){
	++e;int i;
	for(i=1;i<=l;++i){cal(n/G,m/G,(u[i].num-g)/G);u[i].F=(aa%k2+k2)%k2;}
	sort(u+1,u+l+1,Cmp);
	if((u[1].F-u[l].F+m/G)>1)res=max(res,1ll*(u[1].F-u[l].F+m/G-1)*n+u[l].num);
	for(i=2;i<=l;++i)if(u[i].F-u[i-1].F>1)res=max(res,1ll*(u[i].F-u[i-1].F-1)*n+u[i-1].num);
}int i,j,cnt,las;main(){
	cin>>n>>m>>A;for(i=1;i<=A;++i)cin>>a[i];cin>>B;for(i=1;i<=B;++i)cin>>b[i];
	if(n>m){swap(n,m);swap(A,B);swap(a,b);}
	sort(a+1,a+A+1);sort(b+1,b+B+1);
	x=n-1;while(x+A>=n&&a[x+A-n+1]==x)--x;res=max(res,x);
	x=m-1;while(x+B>=m&&b[x+B-m+1]==x)--x;res=max(res,x);
	f1=f2=1;tmp[0]=-1;
	for(;f1<=A||f2<=B;){
		if(tmp[cnt]==a[f1])++f1;if(tmp[cnt]==b[f2])++f2;
		if((f1<=A&&a[f1]<b[f2])||f2>B)tmp[++cnt]=a[f1],++f1;
		else tmp[++cnt]=b[f2],++f2;
	}G=gcd(n,m);k1=n/G,k2=m/G;
	sort(tmp+1,tmp+cnt+1,cmp);
	for(i=1;i<cnt;++i){
		if(tmp[i]%G!=tmp[i+1]%G){++las;
			l=0;for(j=las;j<=i;++j)u[++l].num=tmp[j];
			solve(tmp[i]%G);las=i;
		}
	}l=0;
	for(++las;las<=cnt;++las)u[++l].num=tmp[las];solve(tmp[cnt]%G);
	if(G==e)cout<<res;else cout<<-1;
}