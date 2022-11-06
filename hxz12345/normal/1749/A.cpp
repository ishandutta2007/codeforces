#include <bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char ch=getchar();
	while ((ch!='-')&&(!isdigit(ch))) ch=getchar();
	if (ch=='-') f=-1,ch=getchar();
	while (isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
int n,m,i,a[1001010],b[1001010];
void Main(){
	n=read();m=read();
	for (i=1;i<=m;i++) a[i]=read(),b[i]=read();
	if (n>m) puts("YES");
	else puts("NO");
	return ;
}
int main() {
	int Testing=read();
	for (;Testing;Testing--) Main();
	return 0;
}