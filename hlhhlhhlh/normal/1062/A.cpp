// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
int i,j,k;
int n,a[maxn],l,ans;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int main(){
	n=read();
	a[1]=0;
	for (i=2;i<=n+1;i++){
		a[i]=read();
	}
	a[n+2]=1001;
	n=n+2; l=1; ans=0;
	for (i=1;i<=n;i++){
		if (a[i]!=a[i+1]-1){
			if (i-l+1>=2){
				ans=max(ans,(i-l+1-2));
			}
			l=i+1;
		}
	}
	printf("%d\n",ans);
	return 0;
}