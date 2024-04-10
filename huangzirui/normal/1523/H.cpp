// CF
#include<bits/stdc++.h>
using namespace std;
# define ll long long
# define read read1<ll>()
# define Type template<typename T>
Type T read1(){
	T t=0;
	char k;
	bool vis=0;
	do (k=getchar())=='-'&&(vis=1);while('0'>k||k>'9');
	while('0'<=k&&k<='9')t=(t<<3)+(t<<1)+(k^'0'),k=getchar();
	return vis?-t:t;
}
# define fre(k) freopen(k".in","r",stdin);freopen(k".out","w",stdout)
# define log2 LOG2
int s,m,a[20005],f[15][31][20005],st[15][200005],A[31];
int Max_(int x,int y){return x+a[x]>y+a[y]?x:y;}
int main(){
	s=read,m=read;
	auto log2=[=](double x)->int{return x==1?0:((*(unsigned ll*)&x>>52)&1023)+1;};
	auto query=[=](int l,int r){
		int x=log2(r-l+1);
		return Max_(st[x][l],st[x][r-(1<<x)+1]);
	};
	for(int i=1;i<=s;++i)a[i]=read,st[0][i]=i,a[i]+i>s&&(a[i]=s-i+1);
	st[0][s+1]=s+1;a[s+1]=1;
	for(int i=0;(1<<i+1)<=s+1;++i)
		for(int j=1;j+(1<<i+1)-1<=s+1;++j)
			st[i+1][j]=Max_(st[i][j],st[i][j+(1<<i)]);
	for(int i=0;(1<<i)<=s;++i)
		for(int j=0;j<=30;++j)
			f[i][j][s+1]=s+1;
	for(int i=1;i<=s;++i){
		f[0][0][i]=query(i+1,i+a[i]);
		for(int j=1;j<=30;++j)
			f[0][j][i]=min(i+j+a[i],s+1);
	}
	for(int i=1;(1<<i)<=s;++i){
		auto g=f[i],h=f[i-1];
		for(int j=0;j<=30;++j)
			for(int k=0;k+j<=30;++k)
				for(int l=1;l<=s;++l)
					g[j+k][l]=Max_(g[j+k][l],h[j][h[k][l]]);
	}while(m--){
		int l=read,r=read,k=read,ans=2;
		if(l==r){puts("0");continue;}
		if(l+a[l]+k>=r){puts("1");continue;}
		fill(A,A+k+1,l);
		int x=log2(r-l+1)+1;
		while(x--){
			auto g=f[x];bool vis=1;
			for(int i=0;i<=k&&vis;++i)
				for(int j=0;i+j<=k;++j){
					int p=g[i][A[j]];
					if(p+a[p]+k-i-j>=r){vis=0;break;}
				}
			if(!vis)continue;
			ans+=1<<x;
			for(int i=k;~i;--i)
				for(int j=k-i;~j;--j)
					A[i+j]=Max_(A[i+j],g[j][A[i]]);
		}printf("%d\n",ans);
	}
	return 0;
}