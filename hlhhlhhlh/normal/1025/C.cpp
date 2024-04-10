// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=500010;
int i,j,k;
int n,m,t,ans,l,r;
char c=' ';
int a[maxn*10],b[maxn*10];
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int main(){
	while ((c<'a')||(c>'z')){ c=getchar(); }
	while ((c>='a')&&(c<='z')){ n++; a[n]=(c=='b'); b[n]=a[n]; c=getchar(); }
	if (n<=3){
		for (i=1;i<=n;i++){
			t=t+a[i];
		}
		if ((t==0)||(t==n)){
			printf("1\n");
		}
		else printf("%d\n",n);
		return 0;
	}
	ans=1; l=1; r=n;
	for (i=1;i<=n;i++){
		if (a[l]!=a[r]){
			r++; a[r]=a[l]; l++;
		}
	}
	t=1;
	for (i=l+1;i<=r;i++){
		if (a[i]!=a[i-1]){
			t++; ans=max(ans,t);
		}
		else t=1;
	}
	memset(a,0,sizeof(a)); l=1; r=n;
	for (i=1;i<=n;i++) a[i]=b[n-i+1];
	for (i=1;i<=n;i++){
		if (a[l]!=a[r]){
			r++; a[r]=a[l]; l++;
		}
	}
	t=1;
	for (i=l+1;i<=r;i++){
		if (a[i]!=a[i-1]){
			t++; ans=max(ans,t);
		}
		else t=1;
	}
	printf("%d\n",ans);
	return 0;
}