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
int n,Q;
int a[N];
void MAIN(){
    int op,x,A=0;
    n=read();Q=read();
    for(int i=1;i<=n;++i) {
    	a[i]=read();
    	if(a[i]) ++A;
	}
    while(Q--){
    	op=read();x=read();
    	if(op==1){
    		if(a[x]) --A;
    		else ++A;
    		a[x]^=1;
		}
		else{
			if(A>=x) puts("1");
			else puts("0");
		}
	}
	return;
}

int main(){
    int ttt=1;
    while(ttt--) MAIN();
    return 0;
}