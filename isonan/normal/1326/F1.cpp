#include <cstdio>
#define pop(i) __builtin_popcount(i)

int n,lim;
long long f[19][262144],g[19][262144],fin[262144],t[262144];
bool know[101][101];
void FMT(long long *a){
	for(int i=1;i<lim;i<<=1)
		for(int j=0;j<lim;j+=(i<<1))
			for(int k=0;k<i;k++)
				a[i+j+k]+=a[j+k];
}
void IFMT(long long *a){
	for(int i=1;i<lim;i<<=1)
		for(int j=0;j<lim;j+=(i<<1))
			for(int k=0;k<i;k++)
				a[i+j+k]-=a[j+k];
}
int num[19];
struct Num{
	long long num;
	int p;
	operator long long(){return p?0:num;}
	Num(long long n=1){num=n;p=0;}
	operator*=(long long n){n?num*=n:++p;}
	operator/=(long long n){n?num/=n:--p;}
}tem[262144];
long long v,cnt;
void dfs2(int stat,int res){
	if(res==1){
		fin[stat]=v;
		return;
	}
	for(int i=1;i<=n;i++)
		if(num[i]){
			--num[i];
			dfs2(((stat<<1)|1)<<(i-1),res-1);
			++num[i];
		}
}
void dfs(int res,int last){
	if(!res){
		v=0;
		for(int i=0;i<(1<<n);i++)v+=(n%2==pop(i)%2)?(long long)tem[i]:-tem[i];
		dfs2(0,cnt);
		return;
	}
	for(int i=last;i<=res;i++){
		++num[i];
		++cnt;
		for(int j=0;j<(1<<n);j++)tem[j]*=g[i][j]; 
		dfs(res-i,i);
		for(int j=0;j<(1<<n);j++)tem[j]/=g[i][j];
		--num[i];
		--cnt;
	}
}
int main(){
	scanf("%d",&n);
	lim=1<<n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%1d",&know[i][j]);
	for(int i=0;i<n;i++)f[i][1<<i]=1;
	for(int i=0;i<(1<<n);i++)
		for(int j=0;j<n;j++)
			if(f[j][i]){
				g[pop(i)][i]+=f[j][i];
				for(int k=0;k<n;k++)
					if(!(i&(1<<k))&&!know[j][k])
						f[k][i|(1<<k)]+=f[j][i];
			}
	for(int i=0;i<=n;i++)FMT(g[i]);
	dfs(n,1);
	lim>>=1;
	IFMT(fin);
	for(int i=0;i<(1<<(n-1));i++)printf("%lld ",fin[i]);
}