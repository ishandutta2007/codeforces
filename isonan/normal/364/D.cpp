#include <algorithm>
#include <cstdlib>
#include <cstring> 
#include <cstdio>
#include <ctime>

int n;
int _gcd[2001][2001];
int stat[1000001];
long long a[1000001],ans,r[1000001];
long long pri[2][13],top,val[1000001],Pow[13][13];
long long gcd(long long a,long long b){
	if(a<=2000&&b<=2000)return _gcd[a][b];
	return (!b)?a:gcd(b,a%b);
}
void dfs(int x,int stat,long long val){
	if(x>top){
//		printf("%d %d %d\n",stat,val,::val[stat]);
		if(::val[stat]>=((n+1)>>1))ans=std::max(ans,val);
		return;
	}
	for(int j=0;j<=pri[1][x];j++){
		dfs(x+1,(stat*(pri[1][x]+1))+j,val);
		val*=pri[0][x];
	}
}
long long read(){
	long long x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d",&n);
	srand(time(0));
	for(int i=0;i<=2000;i++)
		for(int j=0;j<=2000;j++)
			_gcd[i][j]=(!j)?i:_gcd[j][i%j];
	for(int i=1;i<=n;i++)a[i]=read();
	for(int fd=1;fd<=15;fd++){
		int x=(1ll*rand()*rand())%n+1;
		long long tem=a[x];
		top=0;
		int mx=1;
		for(long long i=2;i*i<=tem;i++)
			if(tem%i==0){
				pri[0][++top]=i;
				pri[1][top]=0;
				while(tem%i==0)tem/=i,++pri[1][top];
			}
		if(tem>1){
			pri[0][++top]=tem;
			pri[1][top]=1;
		}
		for(int i=1;i<=top;i++)mx*=pri[1][i]+1;
//		printf("%d\n",mx);
		memset(val,0,mx<<3);
		memset(stat,0,1000001<<2);
		for(int i=1;i<=n;i++)r[i]=1;
		for(int j=top,Mul=1;j;Mul*=pri[1][j--]+1)
			for(long long k=pri[0][j];a[x]%k==0&&k<=1000000;k*=pri[0][j]){
				for(int l=k;l<=1000000;l+=k)
					stat[l]+=Mul;
			}
		for(int i=1;i<=n;i++){
			long long v=gcd(a[i],a[x]);
			int stat=(v<=1000000)?::stat[v]:(mx-1-::stat[a[x]/v]);
			++val[stat];
		}
		for(int i=top,Mul=1;i;Mul*=pri[1][i--]+1){
			for(int j=mx-1;~j;j--){
				if((j/Mul)%(pri[1][i]+1))
					val[j-Mul]+=val[j];
			}
		}
//		printf("%d\n",a[x]);
		dfs(1,0,1);
	}
	printf("%lld\n",ans);
}