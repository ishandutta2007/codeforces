#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define LD long double
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
const LL INF=1e18;
const LD eps=1e-18;
const int N=2e5+10;
const LL P=998244353;
const LD PI=acos(-1.0);
LL qpow(LL x,LL y){
    LL re=1;
    while(y){
        if(y&1) re=re*x%P;
        x=x*x%P;y>>=1;
    }
    return re;
}
int n;
LL a[N];
LL b[N];
int tp;
int q[N];
LL w[N];
void MAIN(){
	int num,u,v,ans=1;
	LL x,now;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	if(n==1){
		puts("1");
		return;
	}
	for(int i=1;i<n;++i){
		b[i]=abs(a[i]-a[i+1]);
	}
	b[0]=1;
	tp=0;q[0]=0;w[0]=1;
	for(int i=1;i<n;++i){
		now=b[i];
		for(int j=tp;j>0;--j){
			x=__gcd(now,w[j]);
			if(x==w[j]) break;
			now=w[j]=x;
		}
		q[++tp]=i;
		w[tp]=b[i];
		num=0;
		for(int j=1;j<=tp;++j){
			if(w[j]!=w[num]){
				q[++num]=q[j];
				w[num]=w[j];
			}
			else{
				q[num]=q[j];
			}
		}
		tp=num;
		ans=max(ans,i-q[0]+1);
	}
	printf("%d\n",ans);
    return;
}

int main(){
    //init();
    int ttt=1;
	scanf("%d",&ttt);
    while(ttt--) MAIN();
    return 0;
}