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
int n,a[100100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int t = 0;
	for(int i = 2; i <= n; i++) {
		if(a[i]) continue;
		t++;
		for(int j = 1; j*i <= n; j++) {
			a[j*i] = t;
		}
	}
	for(int i = 2; i <= n; i++)
		cout << a[i] << " ";
	return 0;
}