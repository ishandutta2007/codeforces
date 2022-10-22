// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=15000010;
const int maxm=1000010;
const int inf=1e9+7;
int i,j,k;
int n,x,y,anss,z;
int a[maxn],p[maxn],r,b[maxm];
int ha[maxn],ans,f[maxn],mx;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int gcd(int x,int y){
	if (y==0) return x;
	return gcd(y,x%y);
}
int main(){
	for (i=2;i<maxn;i++){
		if (a[i]==0){
			a[i]=i; r++; p[r]=i;
		}
		j=1;
		while ((j<=r)&&(p[j]<=a[i])){
			if ((long long)p[j]*i>=maxn) break;
			a[p[j]*i]=p[j];
			j++;
		}
	}
	n=read();
	for (i=1;i<=n;i++){
		b[i]=read(); mx=max(mx,b[i]);
		if (i!=1) anss=gcd(anss,b[i]);
		else anss=b[i];
	}
	if (mx==anss){
		printf("-1\n"); return 0;
	}
	x=anss;
	while (anss!=1){
		if (ha[a[anss]]!=0) ha[a[anss]]=ha[a[anss]]*a[anss]; else ha[a[anss]]=a[anss];
		anss=anss/a[anss];
	}
	ans=inf;
	while (x!=1){
		y=a[x];
		z=0;
		for (j=1;j<=n;j++){
			if ((b[j]/ha[y])%y==0){
				z++;
			}
		}
		ans=min(ans,n-z);
		x=x/a[x];
	}
	memset(p,0,sizeof(p));
	for (i=1;i<=n;i++){
		x=b[i];
		while (x!=1){
			if (ha[a[x]]==0){
				if (p[a[x]]==0){
					f[a[x]]++; p[a[x]]=1;
				}
			}
			x=x/a[x];
		}
		x=b[i];
		while (x!=1){
			p[a[x]]=0;
			x=x/a[x];
		}
	}
	for (i=1;i<maxn;i++){
		ans=min(ans,n-f[i]);
	}
	printf("%d\n",ans);
	return 0;
}