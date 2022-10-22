#include<bits/stdc++.h>
using namespace std;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if (c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
const int maxn=400010;
int T=1,opt;
int n,m,tot;
int a[maxn],b[maxn],ha[maxn];
int mx1,mx2,mi1,mi2,ans;
int main(){

	T=read();
	for (opt=1;opt<=T;opt++){
		n=read(); m=read();
		for (int i=0;i<=n+m;i++) ha[i]=0;
		tot=n+m; mx1=0; mx2=0; mi1=0; mi2=0; ans=0;
		for (int i=1;i<=n;i++) a[i]=0;
		for (int i=n+1;i<=n+m;i++) a[i]=1;
		for (int i=1;i<=tot/2;i++) b[i]=0;
		for (int i=(tot/2)+1;i<=tot;i++) b[i]=1;
		for (int i=1;i<=tot;i++) if (a[i]!=b[i]) mi1++;
		for (int i=1;i<=tot/2;i++) b[i]=1;
		for (int i=(tot/2)+1;i<=tot;i++) b[i]=0;
		for (int i=1;i<=tot;i++) if (a[i]!=b[i]) mx1++;

		for (int i=1;i<=m;i++) a[i]=1;
		for (int i=m+1;i<=n+m;i++) a[i]=0;
		for (int i=1;i<=tot/2;i++) b[i]=0;
		for (int i=(tot/2)+1;i<=tot;i++) b[i]=1;
		for (int i=1;i<=tot;i++) if (a[i]!=b[i]) mx2++;
		for (int i=1;i<=tot/2;i++) b[i]=1;
		for (int i=(tot/2)+1;i<=tot;i++) b[i]=0;
		for (int i=1;i<=tot;i++) if (a[i]!=b[i]) mi2++;
		
		if (tot%2==1){
			for (int i=min(mi2,mi1);i<=max(mx1,mx2);i++) ha[i]=1;
		}
		else{
			for (int i=min(mi2,mi1);i<=max(mx1,mx2);i+=2) ha[i]=1;
		}
		
		ans=0;
		for (int i=0;i<=n+m;i++) ans+=ha[i];
		printf("%d\n",ans);
		for (int i=0;i<=n+m;i++) if (ha[i]==1) printf("%d ",i);
		printf("\n");
	}

	return 0;
}