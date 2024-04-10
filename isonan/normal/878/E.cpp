#include <cstdio>
#include <vector>
#include <algorithm>

const int P=1000000007;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
int n,q,a[100001],pre[100001],sum[100001],mx=-0x7f7f7f7f,fa[100001][21];
struct data{
	int N;
	bool inf;
}num[100001];
data add(data a,data b,int n){
	if(b.inf)return b;
	else if(n>30)return (data){b.N,1};
	else{
		long long v=1ll*a.N+((1ll*b.N)<<(1ll*n));
		if(v>1ll*mx)return (data){0,1};
		else return (data){(int)v,0};
	}
}
int S[100010],Pow[100010];
int slice(int l,int r){return sub(S[l],mul(S[r+1],Pow[r-l+1]));}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",a+i),mx=std::max(mx,a[i]);
	Pow[0]=1;
	for(int i=1;i<=n;i++)Pow[i]=add(Pow[i-1],Pow[i-1]);
	for(int i=n;i;i--)S[i]=add((a[i]%P+P)%P,mul(S[i+1],2));
	for(int i=1;i<=n;i++){
		num[i]=(data){a[i],0};
		int tem=i-1;
		while(tem){
			if(!num[i].inf&&num[i].N<=0)break;
			num[i]=add(num[tem],num[i],tem-pre[tem]);
//			printf("- %d %d %d\n",i,tem,pre[tem]);
			tem=pre[tem];
		}
		pre[i]=tem;
		fa[i][0]=tem;
		for(int j=1;j<=20;j++)
			fa[i][j]=fa[fa[i][j-1]][j-1];
		sum[i]=add(sum[pre[i]],mul(2,slice(pre[i]+1,i)));
//		printf("%d %d %d\n",i,pre[i],sum[i]);
	}
	for(int i=1,l,r;i<=q;i++){
		scanf("%d%d",&l,&r);
		int tem=r;
		for(int j=20;~j;--j)
			if(fa[tem][j]>=l)tem=fa[tem][j];
		printf("%d\n",add(sub(sum[r],sum[tem]),slice(l,tem)));
	}
}