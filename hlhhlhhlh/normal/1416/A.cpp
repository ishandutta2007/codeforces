// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=300010;
int i,j,k;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int T,opt;
int n,a[maxn],ha[maxn],mx[maxn],ans[maxn];
int main(){
	
	T=read();
	for (opt=1;opt<=T;opt++){
		n=read();
		for (i=0;i<=n+5;i++){
			a[i]=0; ha[i]=0; mx[i]=0; ans[i]=0;
		}
		for (i=1;i<=n;i++) a[i]=read();
		for (i=1;i<=n;i++){
			mx[a[i]]=max(mx[a[i]],i-ha[a[i]]);
			ha[a[i]]=i;
		}
		for (i=1;i<=n;i++) mx[i]=max(mx[i],n+1-ha[i]);
		for (i=1;i<=n;i++){
			if (ans[mx[i]]==0) ans[mx[i]]=i;
		}
		ans[0]=1e9;
		for (i=1;i<=n;i++){
			if (ans[i]!=0) ans[i]=min(ans[i],ans[i-1]);
			else ans[i]=ans[i-1];
		}
		for (i=1;i<=n;i++)
			if (ans[i]!=1e9) printf("%d ",ans[i]);
			else printf("-1 ");
		printf("\n");
	}
	
	return 0;
}