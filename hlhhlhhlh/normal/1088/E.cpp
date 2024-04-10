// user:halahen
#include<bits/stdc++.h>
using namespace std;
const long long maxn=1000010;
long long i,j,k;
long long n,x,y;
long long a[maxn];
long long th,f1[maxn],f2[maxn],f3[maxn];
long long f[maxn];
long long ans1,ans2; 
long long read(){
	long long tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
void add(long long x,long long y){
	th++; f2[th]=y; f3[th]=f1[x]; f1[x]=th;
}
void dfs(long long x,long long fa){
	long long i=f1[x];
	f[x]=a[x];
	while (i!=0){
		if (f2[i]!=fa){
			dfs(f2[i],x);
			if (f[f2[i]]>0) f[x]=f[x]+f[f2[i]];
		}
		i=f3[i];
	}
}
void dfs2(long long x,long long fa){
	long long i=f1[x];
	f[x]=a[x];
	while (i!=0){
		if (f2[i]!=fa){
			dfs2(f2[i],x);
			if (f[f2[i]]>0) f[x]=f[x]+f[f2[i]];
		}
		i=f3[i];
	}
	if (f[x]==ans1){
		f[x]=0; ans2++;
	}
}
int main(){
	n=read();
	for (i=1;i<=n;i++){
		a[i]=read();
	}
	for (i=2;i<=n;i++){
		x=read(); y=read();
		add(x,y); add(y,x);
	}
	dfs(1,0);
	ans1=-1e18; for (i=1;i<=n;i++) ans1=max(ans1,f[i]);
	dfs2(1,0);
	ans1=ans1*ans2;
	printf("%I64d %I64d",ans1,ans2);
	return 0;
}