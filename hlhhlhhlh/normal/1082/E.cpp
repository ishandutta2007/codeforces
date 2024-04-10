// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=500010;
int i,j,k;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int n,m,a[maxn],ha[maxn],s[maxn];
int f1[maxn],f2[maxn],f3[maxn],th;
int ans,t,f[maxn],r,tt;
int main(){
	n=read(); m=read();
	for (i=1;i<=n;i++){
		a[i]=read();
		if (a[i]==m) s[i]++;
		th++; f2[th]=i; f3[th]=f1[a[i]]; f1[a[i]]=th;
	}
	for (i=1;i<=n;i++){
		s[i]=s[i-1]+s[i];
	}
	ans=s[n];
	for (i=1;i<=5*1e5;i++){
		if (i==m) continue;
		j=f1[i]; r=0;
		while (j!=0){
			r++; f[r]=f2[j];
			j=f3[j];
		}
		for (j=1;j<=r/2;j++) swap(f[j],f[r-j+1]);
		tt=0;
		for (j=1;j<=r;j++){
			t=s[f[j]]-s[f[j-1]];
			tt=tt-t; if (tt<0) tt=0;
			tt=tt+1;
			ans=max(ans,s[n]+tt);
		}
	}
	printf("%d\n",ans);
	return 0;
}