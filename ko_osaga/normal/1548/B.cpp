#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long lint;
typedef pair<lint, lint> pi;
const int MAXN = 300005;
const int mod = 998244353;

void solve(){
	int n;
	scanf("%d",&n);
	vector<lint> a(n);
	for(int i = 0; i < n; i++) scanf("%lld",&a[i]);
	for(int i = n-1; i > 0; i--){
		a[i] = abs(a[i] - a[i-1]);
	}
	lint dap = 1;
	vector<pi> vect;
	for(int i = 1; i < n; i++){
		for(auto &j : vect){
			j.first = gcd(j.first, a[i]);
			j.second++;
		}
		vect.emplace_back(a[i], 1);
		sort(all(vect));
		vector<pi> nvect;
		for(int j = 0; j < sz(vect); ){
			int k = j;
			lint ret = 0;
			while(k < sz(vect) && vect[j].first == vect[k].first){
				ret = max(ret, vect[k].second);
				k++;
			}
			nvect.emplace_back(vect[j].first, ret);
			if(vect[j].first != 1) dap = max(dap, ret + 1);
			j = k;
		}
		vect = nvect;
	}
	printf("%lld\n", dap);
}

int main(){
	int t; scanf("%d",&t);
	while(t--){
		solve();
	}
}