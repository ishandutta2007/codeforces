#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[1000001];
ll b[1000001];
vector<ll>pf;
ll sum=0;
ll test(ll p){
	ll prv=0,pos=1;
	ll res=0;
	for(int i=1; i<=n ;i++){
		ll mi=min(b[i],p-prv);
		b[i]-=mi;
		res+=mi*(i-pos);
		prv+=mi;
		if(prv==p) prv=0,pos=i;
		prv+=b[i];
		if(prv<=p/2){
			res+=prv;
			pos++;
		}
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		sum+=a[i];
	}
	if(sum==1){
		cout << "-1\n";
		return 0;
	}
	for(int i=2; 1LL*i*i<=sum ;i++){
		if(sum%i==0){
			while(sum%i==0){
				sum/=i;
			}
			pf.push_back(i);
		}
	}
	
	if(sum!=1) pf.push_back(sum);
	ll ans=1e18;
	for(auto cur:pf){
		for(int i=1; i<=n ;i++) b[i]=a[i]%cur;
		ans=min(ans,test(cur));
	}
	cout << ans << endl;
}