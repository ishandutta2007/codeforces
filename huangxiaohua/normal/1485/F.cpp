#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
unordered_map<ll,ll> mp;
int i,j,k,n,m,t;
ll b[200500],res,tmp,pre;

int main(){
	scanf("%d",&t);
	while(t--){
		mp.clear();res=tmp=pre=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%lld",&b[i]);
		}
		mp[0]=1;res=1;
		for(i=1;i<=n;i++){
			tmp=res-mp[-pre];
			res=(res*2-mp[-pre]+M+M)%M;
			pre+=b[i];
			mp[b[i]-pre]+=tmp;mp[b[i]-pre]%=M;
		}
		printf("%lld\n",res);
	}
}