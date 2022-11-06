#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char ch=getchar();
	while ((!isdigit(ch))&&(ch!='-')) ch=getchar();
	if (ch=='-') f=-1,ch=getchar();
	while (isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
long long i, Testing,n,a[1001010];
int main(){
	Testing=read();
	for (;Testing;Testing--){
		n=read();
		for (i=1;i<=n;i++) a[i]=read();
		if (a[1]<a[n]) puts("YES");else puts("NO");
	}
	return 0;
}