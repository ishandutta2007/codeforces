#include<bits/stdc++.h>
using namespace std;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if (c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int T,opt;
int n,m;
int i,j,k;
const int maxn=1010;
int a[maxn],b[maxn];
int ans,thi;
int ha[maxn];
int main(){

	T=read();
	for (opt=1;opt<=T;opt++){
		n=read(); m=read();
		memset(ha,0,sizeof(ha));
		for (i=1;i<=m;i++){
			a[i]=read(); b[i]=read();
			if (a[i]>b[i]) swap(a[i],b[i]);
			ha[a[i]]=1; ha[b[i]]=1;
		}
		ans=0;
		for (i=1;i<=m;i++){
			for (j=i+1;j<=m;j++){
				if ((a[i]<a[j])&&(a[j]<b[i])&&(b[i]<b[j])) ans++;
				if ((a[j]<a[i])&&(a[i]<b[j])&&(b[j]<b[i])) ans++;
			}
		}
		for (i=1;i<=m;i++){
			thi=0;
			for (j=a[i];j<=b[i];j++){
				if (ha[j]==0) thi++;
			}
			ans=ans+min(thi,2*n-2*m-thi);
		}
		ans+=(n-m)*(n-m-1)/2;
		printf("%d\n",ans);
	}

	return 0;
}