// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=500010;
int i,j,k;
char c=' ';
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int a[maxn],n,tot,ans,l,r,b[maxn];
int main(){
	n=read();
	while ((c<'A')||(c>'Z')){ c=getchar(); }
	l=1;
	for (i=1;i<=n+1;i++){
		if (c=='S'){
			if (l<=i-1){
				r++; a[r]=l; b[r]=i-1;
			}
			l=i+1;
		}
		else tot++; 
		if (i!=n) c=getchar();
		else c='S';
	}
	for (i=1;i<=r;i++){
		ans=max(ans,b[i]-a[i]+2);
	}
	for (i=1;i<r;i++){
		if (b[i]+2==a[i+1]){
			ans=max(ans,b[i+1]-a[i]+1);
		}
	}
	ans=min(ans,tot);
	printf("%d\n",ans);
	return 0;
}