#include <cstdio>
#include <cassert>
#define pop(i) __builtin_popcount(i)

int n,lim;
unsigned long long f[19][262144],g[19][262144],fin[262144],t[262144];
bool know[101][101];
void FMT(unsigned long long *a){
	for(int i=1;i<lim;i<<=1)
		for(int j=0;j<lim;j+=(i<<1))
			for(int k=0;k<i;k++)
				a[i+j+k]+=a[j+k];
}
void IFMT(unsigned long long *a){
	for(int i=1;i<lim;i<<=1)
		for(int j=0;j<lim;j+=(i<<1))
			for(int k=0;k<i;k++)
				a[i+j+k]-=a[j+k];
}
int num[19];
long long tem[262144];
unsigned long long v,cnt;
void dfs2(int stat,int res){
	if(res==1){
		fin[stat]+=v;
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
		for(int i=0;i<(1<<n);i++)tem[i]=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=num[i];j++)
				for(int k=0;k<(1<<n);k++)
					tem[k]*=g[i][k];
		for(int i=0;i<(1<<n);i++){
			v+=(n%2==pop(i)%2)?tem[i]:-tem[i];
		}
		dfs2(0,cnt);
		return;
	}
	for(int i=last;i<=res;i++){
		++num[i];
		++cnt;
		dfs(res-i,i);
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
	for(int i=0;i<(1<<(n-1));i++)printf("%llu ",fin[i]);
}