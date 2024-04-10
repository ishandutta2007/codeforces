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
int a[N],b[N];
bool cmp(int x,int y){
	return x>y;
}
bool check(int x){
	int y=x-(int)(x/4);
	int z=x-n;
	LL A=0,B=0;
	if(z>=y){
		A=y*100;
	}
	else{
		A=z*100+a[y-z];
	}
	if(n>=y){
		B=b[y];
	}
	else{
		B=b[n];
	}
	if(A>=B) return 1;
	return 0;
}
void MAIN(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=n;++i) scanf("%d",&b[i]);
	sort(a+1,a+1+n,cmp);
	sort(b+1,b+1+n,cmp);
	for(int i=1;i<=n;++i){
		a[i]+=a[i-1];
		b[i]+=b[i-1];
	}
	int l=n,r=n*4,mid;
	while(l!=r){
		mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",l-n);
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