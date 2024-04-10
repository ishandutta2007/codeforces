#include<cstdio>
#include<map>
#define int long long
using namespace std;
typedef long long ll;
int T,m,tot[110];
map<ll,int> mp;
ll n,x;
ll work(){
	ll ans=0;
	for (int i=0;i<=62;i++){
		int x=(n>>i)&1;
		if (x){
			if (!tot[i]){
				bool flag=false;
				for (int j=i+1;j<=62;j++)
					if (tot[j]){
						flag=true;
						for (int k=i;k<j;k++) tot[k]++;
						tot[i]++; tot[j]--; ans+=(j-i);
						break;
					}
				if (!flag) return -1;
			}
			tot[i]--; 
		}
		tot[i+1]+=(tot[i]>>1);
	}
	return ans;
}
signed main(){
	for (int i=0;i<=62;i++) mp[1ll<<i]=i;
	scanf("%lld",&T);
	while (T--){
		scanf("%lld%lld",&n,&m);
		for (int i=0;i<=62;i++) tot[i]=0;
		for (int i=1;i<=m;i++){
			scanf("%lld",&x);
			tot[mp[x]]++;
		}
		printf("%lld\n",work());
	}
	return 0;
}