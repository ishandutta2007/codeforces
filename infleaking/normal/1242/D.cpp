#include<cstdio>
#include<iostream>
#include<cstring>
#include<unordered_map>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
typedef long long ll;
const ll M=1e7+19;
ll h[M],g[M];
vector<int> buc;
int gethash(ll a){
	int x=a%M;
	while (h[x]&&h[x]!=a)x=(x+1)%M;
	return x;
}
ll n,k,T;
//ll pre[11][1001000];
ll lim=1000000;
ll f(ll n){
//	if (k<=10&&n<=lim)return pre[k][n];
	if (n<k*(k+1)/2)return 0;
	int k1=gethash(n);
	if (h[k1])return g[k1];
	h[k1]=n;
	buc.push_back(k1);
	ll n1=n-k*(k+1)/2,q=n1%k;
	ll x1=n1/k+k+(q!=0),x2=q?x1-q:x1-k;
	if (q==0){
		ll z=f(x1);
		return g[k1]=(x1-z)/k;
	}
	else {
		ll z1=f(x1),z2=f(x2-1);
		ll ans=(x1-z1)/k;
		if (z1==z2&&(x1-z1)%k==0)ans--;
		return g[k1]=ans;
	}
}
int main(){
//	cin>>T;
//	for (int i=1;i<=T;i++)scanf("%lld%lld",&a[i].n,&a[i].s);
//	for (int i=2;i<=10;i++){
//		int cnt=0,id=0;
//		ll sum=0;
//		for (int x=1;x<=lim;x++){
//			if (sum<=lim){
//			if (!pre[i][x])cnt++,sum+=x;
//			if (cnt==i&&sum<=lim){
//				pre[i][sum]=++id;
//				cnt=sum=0;
//			}
//			}
//			if (!pre[i][x])pre[i][x]=pre[i][x-1];
//		}
//	}
	for (cin>>T;T--;){
		scanf("%lld%lld",&n,&k);
		while (buc.size())h[buc.back()]=g[buc.back()]=0,buc.pop_back();
		if (f(n)>f(n-1)){
			printf("%lld\n",(k+1)*f(n));
			continue;
		}
		else {
			ll n1=n-f(n),ans=n1/k*(k+1);
			if (n1%k==0)ans--;
			else ans+=n1%k;
			printf("%lld\n",ans);
		}
//		cout<<p.size()<<endl;
//		return 0;
	}
}