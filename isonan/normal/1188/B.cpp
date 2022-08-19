#include <cstdio>
#include <map>

int n,P,k,a[300001];
std::map<int,long long>map;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int val(int x){
	int ans=0;
	ans=mul(x,k);
	(ans+=P-mul(mul(x,x),mul(x,x)))%=P;
	return ans;
}
int main(){
	scanf("%d%d%d",&n,&P,&k);
	for(int i=1;i<=n;i++)scanf("%d",a+i),map[val(a[i])]++;
	long long ans=0;
	for(std::map<int,long long>::iterator it=map.begin();it!=map.end();++it)ans+=(1ll*(it->second)*((it->second)-1))>>1ll;
	printf("%I64d",ans);
}