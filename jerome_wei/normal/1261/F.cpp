#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Bit = 60;

typedef pair<ll,ll> Pir;
vector<Pir> A,B;

inline void maketrie(ll l,ll r,vector<Pir>& rngs){// the range is : (l, r) // [l+1, r-1]
	for(int i=60;~i;i--){
		ll last = (1ll<<(i+1))-1;
		if( l - (l&last) == r - (r&last))continue;
		if(r & (1ll << i)){
			rngs.push_back(Pir(i,r - (1ll<<i)));
		}
		// if(!(l & (1ll << i))){
		// 	rngs.push_back(Pir(i,l + (1ll<<i)));
		// }
	}
	for(int i=60;~i;i--){
		ll last = (1ll<<(i+1))-1;
		if( l - (l&last) == r - (r&last))continue;
		if(!(l & (1ll << i))){
			// cout << l + (1ll << i) << endl;
			rngs.push_back(Pir(i,l + (1ll<<i)));
		}
	}
	// rngs.push_back(Pir(0,l));
	// rngs.push_bacK(Pir(0,r));
}

vector< pair<ll,int> > op;
typedef pair<ll,int> pi;
void merge(Pir a,Pir b){
	ll Xor = a.second ^ b.second;
	Xor -= Xor & ((1ll<<max(a.first,b.first))-1);
	ll rnglen = 1ll << max(a.first, b.first);
	// L = Xor , R = Xor + rnglen - 1
	// int sz = op.size();
	// cout << a.second << " " << a.second + (1ll << a.first) - 1 << ":" << b.second << " " << b.second + (1ll<<b.first) - 1 << endl;
	// cout << Xor << " " << Xor + rnglen - 1 << endl;
	op.push_back(pi(Xor, 1)), op.push_back(pi(Xor + rnglen, -1));
	
}
const int mod = 998244353;
const int inv2 = (mod+1)>>1;

ll S(ll n){
	return n%mod*((n+1)%mod)%mod*inv2%mod;
}

int main()
{
	int sa, sb;
	cin >> sa;
	for(int i=1;i<=sa;i++){
		ll l,r;scanf("%lld%lld",&l,&r);
		maketrie(l-1,r+1,A);
	}
	cin >> sb;
	for(int i=1;i<=sb;i++){
		ll l,r;scanf("%lld%lld",&l,&r);
		maketrie(l-1,r+1,B);
	}
	for(size_t i=0;i<A.size();i++){
		ll LastXor = -1;
		for(size_t j=0;j<B.size();j++)if(A[i].first > B[j].first){
			if(LastXor != (A[i].second ^ B[j].second) - ((A[i].second ^ B[j].second) & ((1ll << A[i].first)-1))){
				LastXor = (A[i].second ^ B[j].second) - ((A[i].second ^ B[j].second) & ((1ll << A[i].first)-1));
				merge(A[i], B[j]);
			}
		}
	}
	for(size_t j=0;j<B.size();j++){
		ll LastXor = -1;
		for(size_t i=0;i<A.size();i++)if(A[i].first <= B[j].first){
			if(LastXor != (A[i].second ^ B[j].second) - ((A[i].second ^ B[j].second) & ((1ll << B[j].first)-1))){
				LastXor = (A[i].second ^ B[j].second) - ((A[i].second ^ B[j].second) & ((1ll << B[j].first)-1));
				merge(A[i], B[j]);
			}
		}
	}
	sort(op.begin(), op.end());
	// int cur = 0;
	int ans = 0;
	int t = 0;
	for(size_t i=0,j;i<op.size();i=j+1){
		j=i;while(j+1<op.size() && op[j+1].first == op[j].first)++j;
		for(size_t k=i;k<=j;k++)t+=op[k].second;
		// cout << t << ":";
		// cout << i << "to" << j << " with " << op.size() << endl;
		if(t>0){
			// cout << op[j+1].first - 1 << " from " << op[j].first << endl;
			ans += (S(op[j+1].first-1)-S(op[j].first-1))%mod;
			ans %= mod;
			ans += mod;
			ans %= mod;
		}
	}
	cout << ans << endl;
	return 0;
}