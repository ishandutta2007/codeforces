#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=16;
map<int,int> p;
ll sum,n;
ll a[N][5010],c[N];
ll cnt[N];
ll pre[1<<N];
ll box[1<<N],apr[1<<N];
void nex(ll &x){
	ll fr=p[x];
	x=sum-(cnt[fr]-x);
}
ll ans[N],ff[N];
int main(){
	// long long
	cin>>n;
	for (ll i=1;i<=n;i++){
		scanf("%lld",&c[i]);
		for (ll j=1;j<=c[i];j++)scanf("%lld",&a[i][j]),p[a[i][j]]=i,sum+=a[i][j],cnt[i]+=a[i][j];
	}
	if (sum%n!=0){
		cout<<"No"<<endl;
		return 0;
	}
	sum/=n;
	for (ll i=1;i<=n;i++){
		for (ll j=1;j<=c[i];j++){
			ll now=a[i][j];
			ll s=1<<p[now]-1;
			while (1){
				nex(now);
				if (now==a[i][j])break;
				if (s&(1<<p[now]-1)){
					s=-1;
					break;
				}
				s|=1<<p[now]-1;
			}
			if (s==-1)continue;
			box[s]=a[i][j];
			apr[s]=1;
		}
	}
	for (ll i=0;i<1<<n;i++)pre[i]=-100;
	pre[0]=0;
	for (ll i=0;i<1<<n;i++){
		if (pre[i]<0)continue;
		for (ll s=i;s<1<<n;s=(s+1)|i){
			if (apr[s^i]){
				pre[s]=i;
			}
		}
	}
	ll full=(1<<n)-1;
	if (pre[full]<0){
		cout<<"No"<<endl;
		return 0;
	}
	cout<<"Yes"<<endl;
	while (full){
		ll z=pre[full]^full;
		ll now=box[z];
		while (1){
			ll k=p[now];
			ans[p[now]]=now;
			nex(now);
			ff[p[now]]=k;
			if (now==box[z])break;
		}
		full=pre[full];
	}
	for (ll i=1;i<=n;i++)printf("%lld %lld\n",ans[i],ff[i]);
}