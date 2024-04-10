#pragma GCC optimize("-O2")
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<bitset>
#include<ctime>
#include<cstdlib> 
#define LL long long
#define DB double
#define pa pair<LL,int>
#define ctz __builtin_ctz
using namespace std;

inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

inline void Out(int x){
    if(x>9) Out(x/10);
    putchar(x%10+'0'); 
}

LL qpow(LL x,LL y,LL P){
    LL re=1;
    while(y){
        if(y&1) re=re*x%P;
        x=x*x%P;y>>=1;	
    } 
    return re;
}

int n;
int a[20];
int f[40000];
int main(){
//    freopen("1.in","r",stdin);
//    freopen("1.out","w",stdout);
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		sum+=a[i];
	}
//	if(sum&1){
//		puts("NO");
//		return 0;
//	}
//	sum>>=1;
	f[0]=1;
	for(int i=1;i<=n;++i){
		for(int j=sum;j>=a[i];--j)
			f[j]|=f[j-a[i]];
	}
	int x;
	while(sum>=0){
		x=sum>>1;
		if(f[x]&&x+x==sum) {
			puts("YES");
			return 0;
		}
		sum-=360;
	}
	puts("NO");
	return 0;
}
/*
1
0
*/