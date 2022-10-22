#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
ll a[110000],d[110000],m[110000],s[110000];
char Getchar(){
	static char now[1<<20],*S,*T;
	if (T==S){
		T=(S=now)+fread(now,1,1<<20,stdin);
		if (T==S) return EOF;
	}
	return *S++;
}
int read(){
	int x=0,f=1;
	char ch=Getchar();
	while (ch<'0'||ch>'9'){
		if (ch=='-') f=-1;
		ch=Getchar();
	}
	while (ch<='9'&&ch>='0') x=x*10+ch-'0',ch=Getchar();
	return x*f;
}
int main(){
	n=read(); k=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) d[i]=read();
	for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	m[1]=d[1]; for (int i=2;i<=n;i++) m[i]=min(m[i-1],d[i]);
	if (k==0){
		ll ans=0;
		for (int i=1;i<=n;i++) ans=max(ans,s[n]-s[i-1]-d[i]);
		printf("%lld\n",ans);
	} else
		if (k>=2){
			ll ans=0; ans=max(ans,max(a[n]-d[n],s[n]-m[n-1]));
			printf("%lld\n",ans); 
		} else{
			ll ans=0; ans=max(ans,s[n-1]-m[n-1]);
			for (int i=1;i+1<=n;i++) ans=max(ans,s[n]-m[i]-d[i+1]);
			for (int i=1;i+2<=n;i++) ans=max(ans,s[n]-d[1]-a[i+1]);
			for (int i=1;i+2<=n;i++) ans=max(ans,s[n]-d[1]-d[i+1]);
			for (int i=2;i<=n;i++) ans=max(ans,s[n]-s[i-1]-d[i]);
			printf("%lld\n",ans);
		}
	return 0;
}