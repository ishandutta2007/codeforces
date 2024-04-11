#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const ll mod = 7 * 17 * (1 << 23) + 1;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n,x,a[1<<20];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> x;
	set<int> z;
	int t = 1, l = 0;
	z.insert(0);
	for(int i = 0;; i++, l++) {
		while(z.count(x^t)) t++;
		if(t>=(1<<n)) break;
		z.insert(t);
		a[l] = t;
		t++;
	}
	cout << l << "\n";
	if(l)
	cout << a[0] << " ";
	for(int i = 1; i < l; i++)
		cout << (a[i]^a[i-1]) << " ";
	return 0;
}