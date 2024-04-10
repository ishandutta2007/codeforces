#include <cstdio>

int n,m;
const int P=998244353;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
long long a[200001],p[65],stk[65],top,C[65][65];
int Pow[200001];
struct base{
	long long Base[65],cnt;
	void add(long long x){
		for(int i=m-1;~i;--i)
			if(x&(1ll<<i)){
				if(!Base[i]){
					Base[i]=x;
					++cnt;
					break;
				}
				x^=Base[i];
			}
	}
	void solve(){
		for(int i=0;i<m;i++)
			for(int j=i+1;j<m;j++)
				if(Base[j]&(1ll<<i))Base[j]^=Base[i];
	}
	void dfs(int now,long long stat){
		if(now>top){
			++p[__builtin_popcountll(stat)];
			return;
		}
		dfs(now+1,stat);
		dfs(now+1,stat^stk[now]);
	}
	void getans(){
		top=0;
		for(int i=0;i<m;i++)if(Base[i])stk[++top]=Base[i];
		dfs(1,0);
	}
}A,B;
int qsm(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=mul(ans,a);
		a=mul(a,a);
		b>>=1;
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<=m;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=add(C[i-1][j],C[i-1][j-1]);
	} 
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
		A.add(a[i]);
	}
	A.solve();
	if(A.cnt<=(m>>1)){
		A.getans();
		for(int i=0;i<=m;i++)printf("%d ",mul(p[i],qsm(2,n-A.cnt)));
	}
	else{
		for(int i=0;i<m;i++)
			if(!A.Base[i]){
				B.Base[i]=1ll<<i;
				for(int j=0;j<m;j++)
					if(A.Base[j]&&(A.Base[j]&(1ll<<i)))
						B.Base[i]|=1ll<<j;
			}
		B.getans();
		for(int i=0;i<=m;i++){
			int fin=0;
			for(int j=0;j<=m;j++){
				int tem=0;
				for(int k=0;k<=j;k++)tem=((k&1)?sub:add)(tem,mul(C[j][k],C[m-j][i-k]));
				fin=add(fin,mul(tem,p[j]));
			}
			printf("%d ",mul(mul(fin,qsm((P+1)>>1,m-A.cnt)),qsm(2,n-A.cnt)));
		}
	}
}