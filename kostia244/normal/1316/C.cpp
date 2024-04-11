#define dominance 1
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 2e6 + 55;//, mod = 1e9 + 7;
ll n, m, p, shift = 0;
vi a, b;
int main() {
	assert(dominance);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> p;
	a.resize(n);
	b.resize(m);
	for(auto &i : a) cin >> i;
	for(auto &i : b) cin >> i;
	reverse(all(a));
	reverse(all(b));
	while(a.back()%p == 0 && b.back()%p == 0) a.pop_back(), b.pop_back(), shift++;
	reverse(all(a));
	reverse(all(b));
	if(b[0]%p==0) {
		swap(a, b);
	}
	int i = 0;
	while(a[i]%p==0) i++;
	cout << 2*shift + i;
}