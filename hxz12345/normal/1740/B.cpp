#include <bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char ch=getchar();
	while ((ch!='-')&&(!isdigit(ch))) ch=getchar();
	if (ch=='-') f=-1,ch=getchar();
	while (isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
long long a[1001010],b[1001010],n,down,i,mx;
void Main(){
	n=read();
	for (i=1;i<=n;i++) {
		a[i]=read();
		b[i]=read();
		if (a[i]>b[i]) swap(a[i],b[i]);
	}
	down=0;mx=0;
	for (i=1;i<=n;i++)
	   down=down+a[i],mx=max(mx,b[i]);
	printf("%lld\n",(mx+down)*2);
	return ;
}
int main() {
	int Testing=read();
	for (;Testing;Testing--) Main();
	return 0;
}