#include <cstdlib>
#include <cstdio>
#include <vector>
#include <random>
#include <ctime>
#include <map>

int n,m;
long long ans;
int l[200010],r[200010],Cnt[200010],len[200010];
std::map<unsigned long long,long long>map,cnt;
unsigned long long val[200010],a[200010],b[200010];
int main(){
	std::mt19937 rnd(998244353);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=0;j<63;j++)
			if(rnd()%2)val[i]|=(1ull<<(unsigned long long)j);
	for(int i=1;i<=n;i++){
		scanf("%d%d",l+i,r+i),++Cnt[l[i]],--Cnt[r[i]+1];
		a[l[i]]^=val[i],a[r[i]]^=val[i];
	}
	cnt[0]++;
	for(int i=1;i<=m;i++){
		a[i]^=a[i-1];
		b[i]=b[i-1];
		ans+=map[b[i]]+cnt[b[i]]*i;
		b[i]^=a[i];
		map[b[i]]-=i;
		cnt[b[i]]++;
//		printf("%lld\n",ans);
	}
	for(int i=1,len=0;i<=m;i++){
		Cnt[i]+=Cnt[i-1];
		if(!Cnt[i])++len;
		else len=0;
		::len[i]=len;
	}
	for(int i=m,len=0;i;i--){
		if(!Cnt[i])++len;
		else len=0;
		ans-=1ll*::len[i]*len;
	}
	printf("%lld\n",ans);
}