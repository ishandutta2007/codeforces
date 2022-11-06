#include <bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char ch=getchar();
	while ((ch!='-')&&(!isdigit(ch))) ch=getchar();
	if (ch=='-') f=-1,ch=getchar();
	while (isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
int n,x,y,i;
void Main(){
	n=read();y=0;
	for (i=1;i<=n*2;i++){
		x=read();if (x % 2==1)y++; 
	}
	if (y*2==n*2) puts("Yes");
	else puts("No");
	return ;
}
int main() {
	int Testing=read();
	for (;Testing;Testing--) Main();
	return 0;
}