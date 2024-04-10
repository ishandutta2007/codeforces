#include <cstdio>
#include <cstring>
#include <algorithm>

int n,b[61],r[61],q,inv;
char str[61];
int num[61];
long long tem[61],orig[61][61];
struct matrix{
	long long a[61][61],b[61][61],P,num[61],tem[61];
	long long p;
	int mul(const int &a,const int &b){return 1ll*a*b%P;}
	int add(int a,const int &b){a+=b;return(a>=p)?a-P:a;}
	int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
	int qsm(int a,int b){
		int ans=1;
		while(b){
			if(b&1)ans=mul(ans,a);
			a=mul(a,a);
			b>>=1;
		}
		return ans;
	}
	void getinverse(){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				b[i][j]=(i==j);
		for(int i=1;i<=n;++i){
			for(int j=i;j<=n;++j)
				if(a[j][i]){
					for(int k=1;k<=n;++k)std::swap(a[j][k],a[i][k]),std::swap(b[j][k],b[i][k]);
					break;
				}
			for(int j=1;j<=n;++j)a[i][j]%=P,b[i][j]%=P;
			int Mul=qsm(a[i][i],P-2);
			for(int j=1;j<=n;++j)a[i][j]=mul(a[i][j],Mul),b[i][j]=mul(b[i][j],Mul);
			for(int j=i+1;j<=n;++j)
				if(a[j][i]){
					int v=P-(a[j][i]%P);
					for(int k=1;k<=n;++k){
						if((a[j][k]+=1ll*v*a[i][k])>=p)a[j][k]-=p;
						if((b[j][k]+=1ll*v*b[i][k])>=p)b[j][k]-=p;
					}
				}
		}
		for(int i=n;i;--i){
			for(int j=1;j<=n;++j)a[i][j]%=P,b[i][j]%=P;
			for(int j=i-1;j;--j)
				if(a[j][i]){
					int v=P-(a[j][i]%P);
					for(int k=1;k<=n;++k){
						if((a[j][k]+=1ll*v*a[i][k])>=p)a[j][k]-=p;
						if((b[j][k]+=1ll*v*b[i][k])>=p)b[j][k]-=p;
					}
				}
		}
	}
	void solve(){
		for(int i=1;i<=n;i++)tem[i]=(::num[i]+P)%P,num[i]=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if((num[j]+=1ll*b[j][i]*tem[i])>=p)num[j]-=p;
		for(int i=1;i<=n;i++)num[i]%=P;
	}
}m[2];
void crt(){
//	for(int i=1;i<=n;i++)printf("%d ",m[0].num[i]);putchar('\n');
//	for(int i=1;i<=n;i++)printf("%d ",m[1].num[i]);putchar('\n');
	for(int i=1;i<=n;i++)tem[i]=((1ll*(m[1].num[i]+1000000007-m[0].num[i])*inv)%1000000007)*998244353+m[0].num[i];
}
bool vis[61];
void dfs(int x){
	if(vis[x]||x>n)return;
	vis[x]=1;
	if(str[x]=='R')dfs(r[x]);
	else dfs(b[x]);
}
int main(){
	scanf("%d",&n);
	--n;
	for(int i=1;i<=n;i++)scanf("%d%d",b+i,r+i);
	m[0].P=998244353;
	m[0].p=998244353ll*998244353ll;
	m[1].P=1000000007;
	m[1].p=1000000007ll*1000000007ll;
	inv=m[1].qsm(998244353,1000000005);
	for(int fd=0;fd<2;fd++){
		memset(orig,0,sizeof orig);
		for(int i=1;i<=n;i++){
			m[fd].a[i][i]=2;
			orig[i][i]=2;
			if(b[i]<=n)(m[fd].a[b[i]][i]+=m[fd].P-1)%=m[fd].P,orig[b[i]][i]--;
			if(r[i]<=n)(m[fd].a[r[i]][i]+=m[fd].P-1)%=m[fd].P,orig[r[i]][i]--;
		}
		m[fd].getinverse();
	}
//	for(int i=1;i<=n;i++,putchar('\n'))
//		for(int j=1;j<=n;j++)
//			printf("%d ",orig[i][j]);
	scanf("%d",&q);
	for(int i=1,v;i<=q;i++){
		scanf("%d%s",&v,str+1);
		memset(num,0,sizeof num);
		for(int i=1;i<=n;i++)
			if(str[i]=='R'){
				num[i]++;
				if(b[i]<=n)num[b[i]]--;
			}
		++num[1],--num[v];
//		for(int i=1;i<=n;i++)printf("%d ",num[i]);putchar('\n');
		m[0].solve(),m[1].solve();
		crt();
		bool cando=1;
//		for(int i=1;i<=n;i++)printf("%lld ",tem[i]);putchar('\n');
		for(int i=1;i<=n;i++){
			long long v=0;
			for(int j=1;j<=n;j++)v+=1ll*tem[j]*orig[i][j];
			if(v!=num[i])cando=0;
		}
		for(int i=1;i<=n;i++)if(!tem[i]&&str[i]=='R')cando=0;
		for(int i=1;i<=n;i++)
			if(tem[i]){
				memset(vis,0,sizeof vis);
				dfs(i);
				if(!vis[v])cando=0;
			}
		if(!cando)puts("-1");
		else{
			long long ans=0;
			for(int i=1;i<=n;i++)ans+=(tem[i]<<1ll)-(str[i]=='R');
			printf("%lld\n",ans);
		}
	}
}