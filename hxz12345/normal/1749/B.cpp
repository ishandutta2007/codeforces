#include <bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char ch=getchar();
	while ((ch!='-')&&(!isdigit(ch))) ch=getchar();
	if (ch=='-') f=-1,ch=getchar();
	while (isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
long long n,i,a[1001010],b[1001010],ans;
void Main(){
	n=read();
	for (i=1;i<=n;i++) a[i]=read();
	for (i=1;i<=n;i++) b[i]=read();
	ans=0;
	for (i=1;i<=n;i++) ans=ans+a[i];
	sort(b+1,b+n+1);
	for (i=1;i<n;i++) ans=ans+b[i];
	printf("%lld\n",ans);
	return ;
}
int main() {
	int Testing=read();
	for (;Testing;Testing--) Main();
	return 0;
}