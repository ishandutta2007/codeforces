#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<cstring>
#include<map>
#define LL long long
using namespace std;

inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void Out(int x){
	if(x>9) Out(x/10);
	putchar('0'+x%10);
}
int gcd(int x,int y){
	if(!y) return x;
	return gcd(y,x%y);
}
LL qpow(LL x,LL y,LL P){
	LL re=1;
	while(y){
		if(y&1) re=re*x%P;
		x=x*x%P;y>>=1;
	}
	return re;
}
const int N=2e5+10;
const LL P=1e9+7;
struct node{
	LL x;
	int id,op;
}a[N];
int n,m,k;
bool cmpx(node A,node B){return A.x>B.x;}
bool cmpi(node A,node B){return A.id<B.id;}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;++i){
		scanf("%I64d",&a[i].x);
		a[i].id=i;
	}
	LL ans=0;
	sort(a+1,a+1+n,cmpx);
	for(int i=1;i<=m*k;++i){
		ans+=a[i].x;
		a[i].op=1;
	}
	sort(a+1,a+1+n,cmpi);
	printf("%I64d\n",ans);
	int j=0;
	for(int i=1;i<k;++i){
		int y=0;
		while(1){
			++j;
			y+=a[j].op;
			if(y==m) break;
		}
		printf("%d ",j);
	}
	puts("");
	return 0;
} 
/*

*/