#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 1e3+7;
ll A[N];
void solve(){
	int n,k;
	cin>>n>>k;
	set<ll> S;
	for(int i = 1;i<=n;i+=1){
		ll mult = 1;
		for(int j = 0;j<k;j+=1){
			int val;
			cin>>val;
			A[i] += val*mult;
			mult *= 3;
		}
		S.insert(A[i]);
	}
	ll SU = 0;
	{
		ll mult = 1;
		for(int i = 0;i<k;i+=1){
			SU += mult;
			mult *= 3;
		}
	}
	ll ans = 0;
	for(int i = 1;i<=n;i+=1){
		ll res = 0;
		for(int j = 1;j<=n;j+=1){
			if (i==j){
				continue;
			}
			ll a = A[i],b = A[j];
			ll dif = 0;
			ll mult = 1;
			for(int h = 0;h<k;h+=1){
				if (a%3==b%3){
					dif += mult*(a%3);
				}
				else{
					dif += mult*(3-(a%3)-(b%3));
				}
				a /= 3;
				b /= 3;
				mult *= 3;
			}
			res += S.count(dif);
		}
		res /= 2;
		ans += res*(res-1)/2;
//		cout<<res<<' ';
	}
	cout<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
//	cin>>t;
	while(t--){
		solve();
	}
}