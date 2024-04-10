#include <cstdio>

bool map[41][41];
int n,m;
int col[41];
bool bipart=1;
int f1[1048576],f2[1048576],stat[1048576];
void color(int x,int c){
	if(col[x]){
		if(col[x]!=c)bipart=0;
		return;
	}
	col[x]=c;
	for(int i=1;i<=n;i++)
		if(map[x][i])color(i,c^1);
}
int main(){
	scanf("%d%d",&n,&m);
	if(m<3){
		puts("0");
		return 0;
	}
	for(int i=1,u,v;i<=m;i++)
		scanf("%d%d",&u,&v),map[u][v]=map[v][u]=1;
	long long ans=1ll<<(1ll*n);
	int cnt=0,is=0;
	for(int i=1;i<=n;i++)
		if(!col[i]){
			++cnt;
			color(i,2);
			bool iso=1;
			for(int j=1;j<=n;j++)iso&=(!map[i][j]);
			is+=iso;
		}
	ans-=(1ll<<(1ll*cnt))*(1-bipart);
	ans+=2ll<<(1ll*is);
//	printf("%lld\n",ans);
	int mid=n>>1;
	for(int i=1;i<=mid;i++)
		for(int j=1;j<=mid;j++)
			if(map[i][j])
				f1[(1<<(i-1))|(1<<(j-1))]=1;
	int lim=1<<mid;
	for(int i=1;i<lim;i<<=1)
		for(int j=0;j<lim;j+=(i<<1))
			for(int k=0;k<i;k++)
				f1[i+j+k]|=f1[j+k];
	for(int i=mid+1;i<=n;i++)
		for(int j=mid+1;j<=n;j++)
			if(map[i][j])
				f2[(1<<(i-mid-1))|(1<<(j-mid-1))]=1;
	lim=1<<(n-mid);
	for(int i=1;i<lim;i<<=1)
		for(int j=0;j<lim;j+=(i<<1))
			for(int k=0;k<i;k++)
				f2[i+j+k]|=f2[j+k];
	for(int i=0;i<lim;i++)f2[i]=!f2[i];
	for(int i=1;i<lim;i<<=1)
		for(int j=0;j<lim;j+=(i<<1))
			for(int k=0;k<i;k++)
				f2[i+j+k]+=f2[j+k];
	for(int i=1;i<=mid;i++){
		stat[i]=lim-1;
		for(int j=mid+1;j<=n;j++)
			if(map[i][j])
				stat[i]^=1<<(j-mid-1);
	}
	for(int i=0;i<(1<<mid);i++){
		if(f1[i])continue;
		int stat=lim-1;
		for(int j=1;j<=mid;j++)
			if(i&(1<<(j-1)))stat&=::stat[j];
//		printf("%d %lld %d\n",i,f2[stat],mid);
		ans-=2ll*f2[stat];
	}
	printf("%lld\n",ans);
}