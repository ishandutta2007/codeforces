#include <cstdio>
#include <map>
#define int long long

int m,k;
int p[1001][1001];
long long sum[1001];
std::map<long long,int>map;
signed main(){
	scanf("%lld%lld",&m,&k);
	for(int i=0;i<k;++i){
		for(int j=0;j<m;++j)
			scanf("%lld",&p[i][j]),sum[i]+=p[i][j];
	}
	for(int i=k-1;i;--i)sum[i]-=sum[i-1];
	for(int i=1;i<k;++i)++map[sum[i]];
	long long maj;
	int y=-1;
	for(std::map<long long,int>::iterator it=map.begin();it!=map.end();++it)
		if(it->second>2)maj=it->first;
	// for(int i=1;i<k;++i)printf("%lld ",sum[i]);putchar('\n');
	for(int i=1;i<k-1;++i)if(sum[i]!=maj&&sum[i+1]!=maj)y=i;
	if((!~y)&&sum[1]!=maj)y=0;
	if((!~y)&&sum[k-1]!=maj)y=k-1;
	long long v=maj;
	for(int i=0;i<k;++i)
		if(i!=y){
			v=0;
			for(int j=0;j<m;++j)v+=1ll*p[i][j];
			v-=maj*i;
			break;
		}
	long long all=0;
	for(int i=0;i<m;++i)all+=1ll*p[y][i]*p[y][i];
	sum[y]=0;
	for(int i=0;i<m;++i)sum[y]+=p[y][i];
	long long d1=v-(sum[y]-maj*y),v2=0;
	for(int i=0;i<k-2;++i)
		if(i!=y&&(i+1)!=y&&(i+2)!=y){
			for(int j=0;j<m;++j)v2+=1ll*p[i][j]*p[i][j];
			for(int j=0;j<m;++j)v2-=2ll*p[i+1][j]*p[i+1][j];
			for(int j=0;j<m;++j)v2+=1ll*p[i+2][j]*p[i+2][j];
			break;
		}
	for(int i=0;i<k-2;++i)
		if(i==y||(i+1)==y||(i+2)==y){
			if(i!=y)for(int j=0;j<m;++j)v2-=1ll*p[i][j]*p[i][j];
			if((i+2)!=y)for(int j=0;j<m;++j)v2-=1ll*p[i+2][j]*p[i+2][j];
			if((i+1)!=y)for(int j=0;j<m;++j)v2+=2ll*p[i+1][j]*p[i+1][j];else v2=-(v2>>1);
			break;
		}
	for(int i=0;i<m;++i){
		if(all-1ll*p[y][i]*p[y][i]+1ll*(p[y][i]+d1)*(p[y][i]+d1)==v2){
			printf("%lld %lld\n",y,p[y][i]+d1);
			fflush(stdout);
			return 0;
		}
	}
}