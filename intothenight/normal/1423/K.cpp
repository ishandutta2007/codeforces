#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 202;
using vi = vector<int>;
const int MAX_PR = 1'000'000;
bitset<MAX_PR> isprime;
vi eratosthenesSieve(int lim) {
	isprime.set(); isprime[0] = isprime[1] = 0;
	for (int i = 4; i < lim; i += 2) isprime[i] = 0;
	for (int i = 3; i*i < lim; i += 2) if (isprime[i])
		for (int j = i*i; j < lim; j += i*2) isprime[j] = 0;
	vi pr;
	rep(i,2,lim) if (isprime[i]) pr.push_back(i);
	return pr;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    auto P = eratosthenesSieve(1000000);
    vector<int> f;
    for(auto &i : P) {if(i*i>1000000) break;f.push_back(i*i);}
    int t, n;
    for(cin >> t; t--;) {
		cin >> n;
		int x = upper_bound(all(P), n)-P.begin();
		x -= upper_bound(all(f), n)-f.begin();
		cout << x+1 << '\n';
	}
}