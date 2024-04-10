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

const LL P=998244353;
const int N=2050;
LL n,m,k,ans=1;
LL jc[N],ny[N];
int main(){
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin>>n>>m>>k;
    if(m==1){
    	if(k==0) puts("1");
    	else puts("0");
    	return 0;
	}
    ans=m*qpow(m-1,k,P)%P;
    jc[0]=jc[1]=ny[0]=ny[1]=1;
    for(LL i=2;i<=2005;++i) ny[i]=(P-P/i)*ny[P%i]%P;
    for(LL i=2;i<=2005;++i) {
    	ny[i]=ny[i-1]*ny[i]%P;
    	jc[i]=jc[i-1]*i%P;
	}
	ans=ans*jc[n-1]%P*ny[k]%P*ny[n-1-k]%P;
	cout<<ans<<endl;
	return 0;
} 
/*
4 1
1 3 5 7

*/