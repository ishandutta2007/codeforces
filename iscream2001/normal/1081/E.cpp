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
const int N=100050;
int n;
bool flag;
LL ans[N];
LL x=0,y,z,t;
int main(){
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    scanf("%d",&n);
    int m=(n>>1)<<1;
    for(int i=1;i<=(m/2);++i){
    	scanf("%I64d",&y);
    	z=x+1;flag=0;
    	while(z+z+1<=y){
    		t=sqrt(y+z*z);
    		if(t*t==y+z*z){
    			flag=1;
    			ans[i*2-1]=z*z-x*x;
    			ans[i*2]=y;
    			x=t;
    			break;
			}
			++z;
		}
		if(!flag){
			puts("No\n");
			return 0;
		}
	}
	if(n!=m){
		ans[n]=x+x+1;
	}
	puts("Yes");
	for(int i=1;i<=n;++i) printf("%I64d ",ans[i]);
	puts("");
	return 0;
} 
/*
4 1
1 3 5 7

*/