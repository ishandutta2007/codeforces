// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int i,j,k;
int n;
long long ans;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int main(){
	n=read();
	for (i=2;i<=n;i++){
		for (j=i*2;j<=n;j=j+i){
			ans=ans+(j/i)*4;
		}
	}
	printf("%I64d\n",ans);
	return 0;
}