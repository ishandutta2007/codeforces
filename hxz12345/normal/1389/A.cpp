#include <bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char ch=getchar();
	while ((!isdigit(ch))&&(ch!='-')) ch=getchar();
	if (ch=='-') f=-1,ch=getchar();
	while (isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
long long l,r;
int main() {
	int Testing=read();
	for (;Testing;Testing--){
		l=read();r=read();
		if (l*2<=r) printf("%lld %lld\n",l,l*2);
		else puts("-1 -1");
	}
    return 0;
}