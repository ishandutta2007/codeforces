#include <bits/stdc++.h>
#define LL long long
#define LD long double
using namespace std;
const LL P=998244353;
const int N=3e5+10;
const int INF=1e9;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void print(LL x){
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
void pls(LL &x,LL y){
    x+=y;if(x>=P)x-=P;
}

void MAIN(){
    int u,v;
    u=read();v=read();
    if(u>v){
    	puts("NO");
    	return;
	}
	if(u==v){
		puts("YES");
		return;
	}
	int x=0,y=0;
	while(u||v){
		if(u&1) ++x;
		if(v&1) --x;
		u>>=1;v>>=1;
		if(x<0) y=1;
	}
	if(y) puts("NO");
	else puts("YES");
	return;
}

int main(){
    int ttt=read();
    while(ttt--) MAIN();
    return 0;
}