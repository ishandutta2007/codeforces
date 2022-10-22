#include<bits/stdc++.h>
using namespace std;
const int maxn=3000010;
int i,j,k,n,m,a[maxn],ans;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c-'0'<0)||(c-'0'>9)){ if(c=='-') fh=-1; c=getchar(); }
	while ((c-'0'>=0)&&(c-'0'<=9)){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int main(){
	n=read(); m=read();
	ans=1e9;
	for (i=1;i<=n;i++){
		a[i]=read();
		if (m%a[i]==0){
			ans=min(ans,m/a[i]);
		}
	}
	printf("%d\n",ans);
	return 0;
}