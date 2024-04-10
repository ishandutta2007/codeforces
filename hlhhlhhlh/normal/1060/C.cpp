// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=2010;
long long i,j,k;
long long n,m,mx,t,ans;
long long a[maxn],b[maxn];
long long ha1[maxn],ha2[maxn];
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int main(){
	n=read(); m=read();
	for (i=1;i<=n;i++) a[i]=read();
	for (i=1;i<=m;i++) b[i]=read();
	mx=read();
	for (i=1;i<=n;i++) ha1[i]=(1<<30);
	for (i=1;i<=m;i++) ha2[i]=(1<<30);
	for (i=1;i<=n;i++){
		t=0;
		for (j=i;j<=n;j++){
			t=t+a[j];
			ha1[j-i+1]=min(ha1[j-i+1],t);
		}
	}
	for (i=1;i<=m;i++){
		t=0;
		for (j=i;j<=m;j++){
			t=t+b[j];
			ha2[j-i+1]=min(ha2[j-i+1],t);
		}
	}
	for (i=1;i<=n;i++){
		for (j=1;j<=m;j++){
			if (ha1[i]*ha2[j]<=mx){
				ans=max(ans,i*j);
			}
		}
	}
	printf("%I64d\n",ans);
	return 0;
}