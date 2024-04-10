#include <cstdio>
#define int long long

int n,m,cnt;
long long sum,w[200001],base[41],g[41];
void add(long long x){
	for(int i=m;~i;--i)
		if(x&(1ll<<i)){
			if(!base[i]){
				base[i]=x;
				break;
			}
			else x^=base[i];
		}
}
void Do(){
	for(int i=m;~i;--i)
		if(base[i])
		for(int j=m;j>i;--j)
			if(i!=j&&(base[j]&(1ll<<i)))base[j]^=base[i];
}
long long stk[41];
signed f[41][41][65536],top,ans[41];
int count(long long x){
	int cnt=0;
	while(x){
		if(x&1ll)++cnt;
		x>>=1ll;
	}
	return cnt;
}
const int P=998244353;
int add(int a,int b){
	a+=b;return(a>=P)?a-P:a;
}
signed main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",w+i),add(w[i]);
	Do();
	top=0;
	for(int i=0;i<=m;i++)if(base[i])stk[++top]=base[i];
	if(top<=22){
		for(int i=0;i<(1ll<<top);i++){
			long long v=0;
			for(int j=1;j<=top;j++)if(i&(1ll<<(j-1)))v^=stk[j];
			++ans[count(v)];
		}
	}
	else{
		cnt=0;
		for(int i=0;i<=m;i++)if(!base[i])g[i]=cnt++;
		for(int i=1;i<=top;i++){
			int v=stk[i];
			long long tem=0;
			for(int j=0;j<=m;j++)
				if(!base[j]&&(v&(1ll<<j))){
					tem|=1<<g[j];
				}
			stk[i]=tem;
		}
		f[0][0][0]=1;
		for(int i=1;i<=top;i++){
			for(int j=0;j<=i;j++)
				for(int k=0;k<(1ll<<16ll);k++)
					f[i][j][k]=add(f[i-1][j][k],j?f[i-1][j-1][k^stk[i]]:0);
		}
		for(int i=0;i<=top;i++)
			for(int j=0;j<(1ll<<16ll);j++){
				(ans[i+count(j)]+=f[top][i][j])%=P;
			}
	}
	int tem=1;
	for(int i=1;i<=n-top;i++)tem=(1ll*tem*2%P);
	for(int i=0;i<=m;i++)printf("%lld ",1ll*tem*ans[i]%P);
}