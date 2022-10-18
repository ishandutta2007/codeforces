#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i, b, e) for(int i = (b); i < (e); i++)
using vi = vector<int>;

#define f first
#define s second
#define all(s) s.begin(), s.end()
#define pb push_back
#define sz(s) (int)s.size()

	int n, m;
	int suma;
	
bool proboj(int len, vi dl){
	dl[3]--;
	for(int i = 0; i < 4; i++){
		if(dl[i] % len == 1){
			if(i == 3)
				return false;
		}
		else if(dl[i] % len == 0){
			if(i < 3)
				dl[i + 1]--;
			else
				return true; 
		}
		else{
			return false;
		}
	}	
	return false;
}
	
bool good(int len){
	return proboj(len, {n, m, n, m}) or proboj(len, {m, n, m, n});
}

void solve() {
	cin >> n >> m;
	suma = 1ll * (n-1 + m - 1) * 2;
	
	vector<int> ans;
	
	for(int l = 1; l * l <= suma; l++){
		if(suma % l == 0){
			if(good(l))
				ans.pb(l);
			if(good(suma / l))
				ans.pb(suma / l);
		}
	}
	
	sort(all(ans));
	ans.resize(unique(all(ans)) - ans.begin());
	cout << sz(ans) << ' ';
	for(auto & u : ans)
		cout << u << ' ';
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt; cin >> tt;
	FOR(te, 0, tt) solve();
	return 0;
}