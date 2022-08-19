#include <cstdio>
#include <map> 

int a[100001],n,k,divs[100001][21],top[100001],val[100001];
long long stat[100001][2];
std::map<long long,int>map[100001];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=n;i++){
		top[i]=0;
		val[i]=1;
		for(int j=2;j*j<=a[i];j++)
			if(a[i]%j==0){
				++top[i];
				while(a[i]%j==0)++divs[i][top[i]],a[i]/=j;
				if(divs[i][top[i]]%k==0){
					--top[i];
					continue;
				}
				val[i]*=j;
				stat[i][0]=stat[i][0]*k+(divs[i][top[i]]%k);
				stat[i][1]=stat[i][1]*k+(k-(divs[i][top[i]]%k));
			}
		if(a[i]>1){
			val[i]*=a[i];
			stat[i][0]=stat[i][0]*k+1;
			stat[i][1]=stat[i][1]*k+k-1;
		}
		++map[val[i]][stat[i][0]];
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans+=map[val[i]][stat[i][1]];
		if(stat[i][0]==stat[i][1])--ans;
	}
	printf("%I64d\n",ans>>1ll);
}