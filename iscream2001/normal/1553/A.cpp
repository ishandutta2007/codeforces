#include<bits/stdc++.h>
#define LL long long
#define LD long double
using namespace std;
const LL P=998244353;
const int N=5e5+10;
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
void init(){
	return;
}

int n; 
void MAIN(){
	scanf("%d",&n);
	++n;
	n=n/10;
	printf("%d\n",n);
	return;
}
int main(){
//	freopen("1.in","r",stdin);
	init();
	int ttt=1;scanf("%d",&ttt);
	while(ttt--) MAIN();
	return 0;	
}
/*
*/