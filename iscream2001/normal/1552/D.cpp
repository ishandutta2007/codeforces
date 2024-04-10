#include<bits/stdc++.h>
#define LL long long
#define LD long double
using namespace std;
const LL P=998244353;
const int N=1e5+10;
const LL INF=1e18;
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
int n,K;
int a[N];
int B;
int cal(int x){
	int y,z=0,s=0;
	for(int i=0;i<n;++i){
		y=x%3;
		x=x/3;
		y=y-1;
		if(y!=0) ++z;
		s+=y*a[i];
	}
	if(z==0) return -1;
	return s;
}
void MAIN(){
	int u,v;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",&a[i]);
	}
	B=1;
	for(int i=1;i<=n;++i) B=B*3;
	for(int i=0;i<B;++i){
		if(cal(i)==0){
			puts("YES");
			return;
		}
	}
	puts("NO");
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
735134400
*/