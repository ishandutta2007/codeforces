#include <bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char ch=getchar();
	while ((ch!='-')&&(!isdigit(ch))) ch=getchar();
	if (ch=='-') f=-1,ch=getchar();
	while (isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
int n;
void Main(){
    n=read();
    if (n % 2==1) puts("3");
    else puts("2");
	return ;
}
int main() {
	int Testing=read();
	for (;Testing;Testing--) Main();
	return 0;
}