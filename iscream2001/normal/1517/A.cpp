#include <bits/stdc++.h>
#define LL long long
using namespace std;
const LL P=998244353;
const LL INF=1e18;

const int N=1e5+10;
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
LL n,m;
void MAIN(){
	scanf("%lld",&n);m=2050;
	LL x=n%m,y=n/m,ans=0;
	if(x!=0) puts("-1");
	else{
		while(y){
			ans+=y%10;
			y=y/10;
		}
		printf("%lld\n",ans);
	}
	
	return;
}

int main(){
    int ttt=read();
    while(ttt--) MAIN();
    return 0;
}