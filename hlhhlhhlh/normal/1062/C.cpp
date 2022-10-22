// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
const long long mod=1e9+7;
int i,j,k;
int n,q,x,y,tot;
long long ans;
char c=' ';
int a[maxn];
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
long long getax(long long a,long long x){
	long long t1=1,t2=a,t3=1;
	while (x!=0){
		if (x%(t1*2)/t1==1){
			x=x-t1;
			t3=(t3*t2)%mod;
		}
		t1=t1*2; t2=(t2*t2)%mod; 
	}
	return t3;
}
int main(){
	n=read(); q=read();
	while ((c<'0')||(c>'9')){ c=getchar(); }
	for (i=1;i<=n;i++){
		a[i]=c-'0'; c=getchar();
	}
	for (i=1;i<=n;i++) a[i]=a[i]+a[i-1];
	for (i=1;i<=q;i++){
		x=read(); y=read();
		tot=a[y]-a[x-1];
		ans=(getax(2,tot)-1+mod)%mod;
		ans=ans+((getax(2,y-x+1-tot)-1+mod)%mod)*(getax(2,tot)-1+mod);
		ans=ans%mod;
		printf("%d\n",ans);
	}
	return 0;
}