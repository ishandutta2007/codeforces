#include <bits/stdc++.h>

using namespace std;
#define DIM 200007
#define INF 2E63
#define MAXN 10000007
#define MODULO 1000000007 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pairll;
typedef ll arr[DIM];
typedef pairll parr[DIM];
typedef vector<ll> graph[DIM];

ll H, n;
arr A;

int main() {
	//ios_base::sync_with_stdio(0);
	//cin.tie(0); cout.tie(0);
	cin >> H >> n;
	ll r = H;
	ll x,flag = 0,num;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		r += x;
		A[i] = r-H;
		if (r <= 0) {
			flag = 1;
			num = i;
			break;
		}
	}
	if (flag == 1) {
		cout << num << endl;
		return 0;
	}
	if (A[n] >= 0) {
		cout << -1 << endl;
		return 0;
	}
	ll res = INF;
	for (int i = 1; i <= n; i++) {
		ll g = i+(H+A[i])/abs(A[n])*n;
		if ((H + A[i]) % abs(A[n]) != 0)g += n;
		res = min(res, g);
	}
	cout << res << endl;
}