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
const LL P=1e9+7;
LL jc[100010],ny[100010],inv[100010]; 
LL C(LL x,LL y){
	if(x>y) return 0;
	return jc[y]*ny[x]%P*ny[y-x]%P;
}
LL find(LL x,LL y){
	return C(y-1,x+y-1);
}
LL ans1=0,ans2=0;
int tot=0;
LL p[50];
LL cnt[50];
LL n,k;
LL g[70][70],t[70][70];
void solve(int cs,LL x,LL s){
	if(cs>tot){
		//cout<<x<<" "<<s<<endl;
		ans1=(ans1+s*x%P)%P;
		ans2=(ans2+s)%P;
		return;
	}
	LL re;
	for(LL i=0;i<=cnt[cs];++i){
		solve(cs+1,x,s*g[cnt[cs]][i]%P);
		x=x*p[cs]%P;
	}
	return;
}

int main(){
//    freopen("1.in","r",stdin);
//    freopen("1.out","w",stdout);
	jc[0]=jc[1]=ny[0]=ny[1]=inv[0]=inv[1]=1;
	for(LL i=2;i<=20000;++i) inv[i]=(P-P/i)*inv[P%i]%P;
	for(LL i=2;i<=20000;++i){
		ny[i]=inv[i]*ny[i-1]%P;
		jc[i]=jc[i-1]*i%P;
	}
	cin>>n>>k;
	for(int i=0;i<=50;++i) g[i][i]=1;
	LL now;
	for(int tt=1;tt<=k;++tt){
		memset(t,0,sizeof(t));
		for(LL i=0;i<=50;++i){
			now=0;
			for(LL j=i;j>=0;--j){
				now=(now+g[i][j]*inv[j+1]%P)%P;
				t[i][j]=now;
			}
		}
		memcpy(g,t,sizeof(g));
	}
	LL x=n;
	for(LL i=2;i<=sqrt(x);++i){
		if(x%i==0){
			p[++tot]=i;
			while(x%i==0){
				x/=i;
				++cnt[tot];
			}
		}
	}
	if(x>1){
		p[++tot]=x;
		cnt[tot]=1;
	}
	solve(1,(LL)1,(LL)1);
	ans1=ans1*qpow(ans2,P-2,P)%P;
	cout<<ans1<<endl;
	return 0;
}
/*
1
0
*/