#include <bits/stdc++.h>
#define LL long long
#define LD long double
using namespace std;
const LL P=1e9+7;
const int N=3e5+10;
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
int n,m;
LL seed=0;
LL base=0;
LL rnd(){
	LL ret=seed;
	seed=(seed*base+233)%P;
	return ret;
}

int p[200005];
LL k[200005],b[200005],w[200005];
LL t[5000005],a[5000005];
LL ans[5000005];
void MAIN(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i){
    	scanf("%d%lld%lld%lld",&p[i],&k[i],&b[i],&w[i]);
	}
    p[0]=0;
    for(int i=1;i<=m;++i){
    	seed=b[i];
		base=w[i];
		for(int j=p[i-1]+1;j<=p[i];++j){
			t[j]=(rnd()%2)+1;
			a[j]=(rnd()%k[i])+1;
		}
	}
	LL sum1=0,sum2=0;
	for(int i=1;i<=n;++i){
		ans[i]=0;
		if(t[i]==t[1]){
			sum1+=a[i];
		}
		else{
			sum2+=a[i];
		}
	}
	int S=1;
	if(sum1>sum2){
		ans[1]=1;--sum1;--a[1];
		if(sum2){
			for(int i=2;i<=n;++i) if(t[i]!=t[1]){
				S=i;break;
			}
		}
		swap(sum1,sum2);
	}
	LL x=0,y;
	if(sum1){
		for(int i=S;i<=n;++i){
			if(t[i]==t[S]){
				ans[i]+=a[i];
				x+=a[i];
			}
			else{
				y=min(a[i],x);
				ans[i]+=y;
				x-=y;
				a[i]-=y;
			}
		}
		for(int i=1;i<S;++i){
			if(t[i]==t[S]){
				ans[i]+=a[i];
				x+=a[i];
			}
			else{
				y=min(a[i],x);
				ans[i]+=y;
				x-=y;
				a[i]-=y;
			}
		}
		for(int i=S;i<=n;++i){
			if(t[i]!=t[S]){
				y=min(a[i],x);
				ans[i]+=y;
				x-=y;
				a[i]-=y;
			}
		}
		for(int i=1;i<S;++i){
			if(t[i]!=t[S]){
				y=min(a[i],x);
				ans[i]+=y;
				x-=y;
				a[i]-=y;
			}
		}
	}
	LL res=1;
	for(int i=1;i<=n;++i){
		x=ans[i];
		y=(LL)i*i;
		x=x^y;
		++x;
		x=x%P;
		res=res*x%P;
	}
	printf("%lld\n",res);
    return;
}
 
int main(){
    int ttt=1;
    while(ttt--) MAIN();
    return 0;
}