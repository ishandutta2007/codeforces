// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=5010;
int i,j,k;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int T,opt;
long long n,a[maxn],b[maxn];
int tot;
long long ans;
int main(){
	T=read();
	for (opt=1;opt<=T;opt++){
		n=read();
		for (i=1;i<=n;i++) a[i]=read();
		memset(b,0,sizeof(b)); ans=0;
		a[n+1]=0;
		for (i=1;i<=n;i++){
			if (a[i]>n){ b[n+1]+=n-a[i]; }
			for (j=min(n,a[i]);j>=2;j--){
				if (i+j>n) b[n+1]++;
				else{
					b[i+j]++;
				}
			}
			if (b[i]<a[i]-1){
				ans=ans+((a[i]-1)-b[i]);
			}
			else{
				b[i+1]+=b[i]-(a[i]-1);
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}