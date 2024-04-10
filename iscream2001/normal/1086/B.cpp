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
const int N=1e5+10;
int n; 
int du[N];
DB ans=2.0,k;
int main(){
//    freopen("1.in","r",stdin);
//    freopen("1.out","w",stdout);
    scanf("%d%lf",&n,&k);
    //cout<<k<<endl;
    int u,v;
    for(int i=1;i<n;++i){
    	scanf("%d%d",&u,&v);
    	++du[u];++du[v];
	}
	int js=0;
	for(int i=1;i<=n;++i) if(du[i]==1) ++js;
	k=(DB)k/(DB)js;
	k=k+k;
	printf("%0.7lf\n",k);
	return 0;
}
/*






*/