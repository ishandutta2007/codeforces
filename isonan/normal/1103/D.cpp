#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <map> 

long long n,k,tot,tem,val[101],cnt,a[1000001],e[1000001],value[10001];
long long f[13][10001];
std::map<long long,std::vector<int> >map;
long long gcd(long long a,long long b){return (!b)?a:gcd(b,a%b);}
int main(){
	scanf("%d%I64d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%I64d",a+i);
		tot=gcd(tot,a[i]);
	}
	if(tot==1){
		puts("0");
		return 0;
	}
	long long v=1;
	for(long long i=2;i*i<=tot;i++)
		if(tot%i==0){
			val[++cnt]=i;
			while(tot%i==0)tot/=i,v*=i;
		}
	if(tot>1)val[++cnt]=tot,v*=tot;
	for(int i=1;i<=n;i++){
		scanf("%I64d",e+i);
		long long tem=1;
		for(int j=1;j<=cnt;j++)
			while(a[i]%val[j]==0)a[i]/=val[j],tem*=val[j];
		map[tem].push_back(e[i]);
	}
	for(int i=0;i<=cnt;i++)
		for(int j=0;j<1<<cnt;j++)
			f[i][j]=1000000000000000000ll;
	f[0][0]=0;
	for(auto it=map.begin();it!=map.end();++it){
		std::sort((it->second).begin(),(it->second).end());
		long long tem=it->first;
		for(int i=1;i<=cnt;i++){
			value[1<<(i-1)]=1;
			while(tem%val[i]==0)tem/=val[i],value[1<<(i-1)]*=val[i];
		}
		for(int i=1;i<1<<cnt;i++)
			for(int j=1;j<=cnt;j++)
				if(!(i&(1<<(j-1))))value[i|(1<<(j-1))]=value[i]*value[1<<(j-1)];
		for(auto it1=(it->second).begin();it1!=(it->second).end();++it1){
			bool cando=0;
			for(int j=cnt;j;--j)
				for(int i=1;i<1<<cnt;i++)
					for(int stat=0;stat<1<<cnt;stat++)
						if(((i&stat)==stat)&&value[i^stat]<=k&&f[j][i]>f[j-1][stat]+*it1)
							cando=1,f[j][i]=f[j-1][stat]+*it1;
			if(!cando)break;
		}
	}
	long long ans=1000000000000000000ll;
	for(int i=1;i<=cnt;i++)ans=std::min(ans,f[i][(1<<cnt)-1]*i);
	if(ans==1000000000000000000ll)puts("-1");
	else printf("%I64d",ans);
}