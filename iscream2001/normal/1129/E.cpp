#pragma GCC optimize("-O3")
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<cstring>
#include<map>
#include<queue>
#include<set>
#include<cmath>
#include<vector>
#define LL long long
#define ui unsigned int
#define ull unsigned long long
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
LL gcd(LL x,LL y){
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
const double eps=1e-6;
const LL inf=1e18;
const LL P=1e9+7;
int n;

int tp=0;
int L[510],R[510];

void add(int x,int y){
	++tp;L[tp]=x;R[tp]=y;
}
int sz[510];
int a[510],t[510],q[510];
int p[510][510];
void cal(int l,int r,int x,int y){
	//cout<<"now "<<l<<" "<<r<<" "<<x<<" "<<y<<endl;
	if(l>r) return;
	printf("%d\n",1);
    printf("%d\n",1);
    printf("%d\n",r-l+1);
    for(int i=l;i<=r;++i) printf("%d ",q[i]);
    puts("");
    printf("%d\n",y);
    fflush(stdout);
    int re;scanf("%d",&re);
    if(re==r-l+1){
    	for(int i=l;i<=r;++i) p[y][++a[y]]=q[i];
	}
	else if(re==0){
		for(int i=l;i<=r;++i) p[x][++a[x]]=q[i];
	}
	else{
		int mid=l+r>>1;
		cal(l,mid,x,y);
		cal(mid+1,r,x,y);
	}
}
void sol(int x){
	int b=0,y;
	while(a[x]){
		b=0;
		y=p[x][1];
		add(x,y);
		for(int i=2;i<=a[x];++i) q[++b]=p[x][i];
		a[x]=0;
		cal(1,b,x,y);
		sol(y);
	}
} 
bool cmp(int A,int B){
	return sz[A]>sz[B];
}
int main(){
    scanf("%d",&n);
    if(n==2){
    	puts("ANSWER");
    	puts("1 2");
    	return 0;
	}
    for(int i=2;i<=n;++i)
    	p[1][++a[1]]=i;
    for(int i=2;i<=n;++i){
    	printf("%d\n",1);
    	printf("%d\n",1);
    	printf("%d\n",n-2);
    	for(int j=1;j<=n;++j)
    		if(j!=1&&j!=i) printf("%d ",j);
    	puts("");
    	printf("%d\n",i);
    	fflush(stdout);
    	scanf("%d",&sz[i]);
	}
	sort(p[1]+1,p[1]+n,cmp);
	sol(1);
	puts("ANSWER");
	for(int i=1;i<=tp;++i) printf("%d %d\n",L[i],R[i]);
	//fflush(stdout);
	return 0;
}
/*
5
1 2 2
1 2 2
*/