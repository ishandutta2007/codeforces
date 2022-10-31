// Hydro submission #614dccb1c3f0508924d2b801@1632488625849
#include <bits/stdc++.h>
using namespace std;
const int N=10010;
inline int read(){
	int x=0;bool f=false;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=true;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return f?-x:x;
}
inline void write(int x,char ed='\n'){
	if(x<0) putchar('-'),x=-x;
	static int num[30],nm=0;
	do num[++nm]=x%10,x/=10;while(x);
	while(nm) putchar(num[nm--]^48);
	putchar(ed);
}
int n,m;
bitset<N> st[60];
int a[N],c[N];
signed main(){
	n=read();m=read();
	for(int i=1;i<=n;i++){
		int len=read();
		for(int j=1;j<=len;j++)
			st[i][read()]=1;
		for(int j=1;j<i;j++)
			if(!(st[i]&st[j]).count()) return puts("impossible"),0;
	}
	puts("possible");
	return 0;
}