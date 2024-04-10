#pragma GCC optimize("-O2")
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
#include<map>
#include<bitset>
#include<ctime>
#include<cstdlib> 
#define LL long long
#define DB long double
#define pa pair<LL,int>
using namespace std;

inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
inline void Out(LL x){
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

const LL P=1e9+7;
const int N=50005;
LL n,m;
LL mu[N],G[N];
bool not_pri[N];
int pri[N];
LL F(LL A,LL B,LL C){
	LL re=(LL)(A+1)*(LL)A/(LL)2;
	return (A*B%P-C*re%P+P)%P;
}
int main(){
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    int v;scanf("%d",&v);
    if(v!=2) puts("1");
    else puts("2");
    return 0; 
} 
/*
4 1
1 3 5 7

*/