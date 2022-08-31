#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...) // remove in interactive
#define endl '\n'
#endif


const int N = 1e6;
int factor[N], mu[N], tot[N];
void pre(){
    for(int i = 2;i*i<N;i++) if(!factor[i]) for(int j = i*i;j<N;j+=i) factor[j] = i;
    for(int i = 2;i<N;i++) if(!factor[i]) factor[i] = i;
    mu[1] = tot[1] = 1;
    for(int i = 2;i < N; i++){
    	int p = factor[i], x = i/p;
    	mu[i] = (x % p == 0) ? 0 : -mu[x];
        tot[i] = (x % p == 0) ? p * tot[x] : (p - 1) * tot[x];
    }
}
// sum abs(x - v)
ll getSum(ll v, vector<pair<ll, ll>>& pref){
	int n = pref.size();
	int k = upper_bound(all(pref), make_pair(v, -1LL)) - pref.begin();
	// < k -> v - x
	// >= k -> x - v
	ll ret = 0;
	if(k != 0){
		ret += k * v - pref[k - 1].second;
	}
	if(k != n){
		ret += pref.back().second - (k == 0 ? 0LL : pref[k - 1].second) - v * 1LL * (n - k);
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	pre();
	int n; cin >> n;
	vector<ll> a(n + 1), b(n + 1), delta(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	for(int i = 1; i <= n; i++){
		cin >> b[i];
		delta[i] = b[i] - a[i];
	}
	delta[1] = 0;
	vector<ll> U(n + 1);
	vector<vector<ll>> vals(2);
	ll sum = 0;
	for(int j = 1; j <= n; j++){
		for(int d = 1; j * d <= n; d++){
			U[j * d] += mu[d] * delta[j];
		}
		if(mu[j] == 0){
			sum += abs(U[j]);
		} else if(mu[j] == 1){
			vals[0].push_back(U[j]);
		} else{
			vals[1].push_back(U[j]);
		}
	}
	vector<vector<pair<ll, ll>>> pref(2);
	for(int i = 0; i < 2; i++){
		sort(all(vals[i]));
		ll s = 0;
		for(int j = 0; j < sz(vals[i]); j++){
			s += vals[i][j];
			pref[i].push_back({vals[i][j], s});
		}
	}
	// change delta[1]? --> U[i] += delta[1] * mu[i]
	// sum abs(U[i]) = ?
	int q; cin >> q;
	while(q--){
		int x;
		cin >> x;
		ll v = x - a[1];
		cout << sum + getSum(-v, pref[0]) + getSum(v, pref[1]) << endl;
	}
}