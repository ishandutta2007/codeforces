#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char ch=getchar();
	while ((ch!='-')&&(!isdigit(ch))) ch=getchar();
	if (ch=='-') f=-1,ch=getchar();
	while (isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
long long ans,mx,mn,n,a[1001010],i;
void Main(){
	n=read();
	for (i=1;i<=n;i++) a[i]=read();
	if (n==1){
		puts("0");
		return ;
	}
	mx=0;mn=1000;
	for (i=2;i<=n;i++) mx=max(mx,a[i]);
	for (i=1;i<n;i++) mn=min(mn,a[i]);
	ans=0;
	ans=max(ans,max(mx-a[1],a[n]-mn));
	for (i=1;i<=n;i++) ans=max(ans,a[(n+i-2) % n+1]-a[i]);
	printf("%lld\n",ans);
	return ;
}
int main(){
	int Testing=read();
	for (;Testing;Testing--) Main();
	return 0;
}