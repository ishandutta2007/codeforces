#include <cstdio>
#include <cstring>

const int P=998244353;
const long long p=1ll*P*P;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
int qsm(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=mul(ans,a);
		a=mul(a,a);
		b>>=1;
	}
	return ans;
}
int n,c,a[3001];
namespace solve1{
	int f[3010][3010],cnt[3010],pow[3010],inv[3010],ans[3010];
	unsigned long long tem[3010];
	void main(){
		pow[0]=0;
		for(int i=1;i<=n;i++)pow[i]=add(add(pow[i-1],pow[i-1]),1);
		for(int i=0;i<=n;i++)inv[i]=qsm(pow[i],P-2);
		inv[0]=1;
		f[0][0]=1;
		ans[0]=pow[n];
//		printf("%d\n",ans[0]);
		for(int i=1;i<=n;i++){
			memset(cnt,0,sizeof cnt);
			memset(tem,0,sizeof tem);
			int tem=1,Cnt=c-1;
			for(int j=i-1;~j;j--){
				if(!Cnt)
					for(int k=0;k<=(j/c);k++)
						if((solve1::tem[k+1]+=1ll*f[j][k]*tem)>=p)solve1::tem[k+1]-=p;
				if(a[j]!=a[i]){
					tem=mul(tem,mul(inv[cnt[a[j]]],pow[cnt[a[j]]+1]));
					if(!cnt[a[j]])--Cnt;
					++cnt[a[j]];
				}
			}
			for(int j=0;j<=(i/c);j++){
				f[i][j]=solve1::tem[j]%P;
				ans[j]=add(ans[j],mul(f[i][j],add(pow[n-i],1)));
			}
		}
		for(int i=0;i<=n;i++)printf("%d ",sub(ans[i],ans[i+1]));
	}
}
namespace solve2{
	int f[3010][2048],pow[3010],ans[3010];
	void main(){
		pow[0]=1;
		for(int i=1;i<=n;i++)pow[i]=add(pow[i-1],pow[i-1]);
		ans[0]=sub(pow[n],1);
		f[0][0]=1;
		for(int i=1;i<=n;i++){
			for(int j=(i/c);~j;j--){
				for(int k=(1<<c)-1;~k;k--)
					if(k&(1<<(a[i]-1)))f[j][k]=add(mul(f[j][k],2),f[j][k^(1<<(a[i]-1))]);
				ans[j+1]=add(ans[j+1],mul(f[j][(1<<c)-1],pow[n-i]));
				f[j+1][0]=add(f[j+1][0],f[j][(1<<c)-1]);
				f[j][(1<<c)-1]=0;
			}
		}
		for(int i=0;i<=n;i++)printf("%d ",sub(ans[i],ans[i+1]));
	}
}
int main(){
	scanf("%d%d",&n,&c);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	if(c>20||n<=(1<<c))solve1::main();
	else solve2::main();
}