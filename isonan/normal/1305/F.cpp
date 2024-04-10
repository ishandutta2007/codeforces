#include <set>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#define int long long
 
int n,a[200001],ans;
std::set<long long>set;
int gcd(int a,int b){return (!b)?a:gcd(b,a%b);}
void getans(int x){
	if(set.count(x))return;
	set.insert(x);
	int cnt=0;
	for(int i=1;i<=n;i++){
		int y=(a[i]/x)*x,z=a[i]-y,m=x-z;
		if(y>0)m=std::min(m,z);
		cnt+=m;
		if(cnt>=ans)return;
	}
	ans=std::min(ans,cnt);
}
signed main(){
	scanf("%lld",&n);
	ans=n;
	int cnt=1;
	for(int i=1;i<=n;i++)scanf("%lld",a+i),cnt=(cnt+(a[i]^a[i-1]%9982443))%998244353;
	srand(cnt+time(0));
	for(int i=1;i<=200;i++){
		int cnt=0;
		int ind=(1ll*rand()*rand())%n+1;
		cnt=a[ind]-1;
		for(int i=2;i*i<=cnt;i++)
			if(cnt%i==0){
				while(cnt%i==0)cnt/=i;
				getans(i);
			}
		if(cnt>1)getans(cnt);
		cnt=a[ind];
		for(int i=2;i*i<=cnt;i++)
			if(cnt%i==0){
				while(cnt%i==0)cnt/=i;
				getans(i);
			}
		if(cnt>1)getans(cnt);
		cnt=a[ind]+1;
		for(int i=2;i*i<=cnt;i++)
			if(cnt%i==0){
				while(cnt%i==0)cnt/=i;
				getans(i);
			}
		if(cnt>1)getans(cnt);
	}
	printf("%lld\n",ans);
}