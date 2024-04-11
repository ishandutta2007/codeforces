#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7, maxa = 1e5 + 44;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	vector<ll> cnt(maxa, 0), pw(maxa, 1);
	for(int i = 1; i < maxa; i++)
		pw[i] = (pw[i-1]<<1)%mod;
	cin >> n;
	for(int t, i = 0; i < n; i++) {
		cin >> t;
		cnt[t]++;
	}
	for(int i = 1; i < maxa; i++) {
		for(int j = 2*i; j < maxa; j+=i) {
			cnt[i] = (cnt[i]+cnt[j])%mod;
		}
	}
	for(int i = maxa-1; i; i--) cnt[i] = pw[cnt[i]]-1;
	for(int i = maxa-1; i; i--) {
		for(int j = 2*i; j < maxa; j+=i)
			cnt[i] = (mod+cnt[i]-cnt[j])%mod;
	}
	cout << cnt[1];
}