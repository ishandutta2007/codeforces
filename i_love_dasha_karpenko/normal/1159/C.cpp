#include <bits/stdc++.h>

using namespace std;
#define DIM 100007
#define INF 10E16
#define MAXN 10000007
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pairll;
typedef ll arr[DIM];
typedef pairll parr[DIM];
set<ll> S;
ll n, m;
arr A,B,V;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)cin >> A[i];
	for (int i = 1; i <= m; i++)cin >> B[i];
	sort(A + 1, A + 1+n);
	sort(B + 1 , B + 1+m);
	if (A[n] > B[1]) {
		cout << -1 << endl;
		return 0;
	}
	ll res = 0,lastvis = m;
	for (int i = n; i >= 1; i--) {
		ll flag = 0;
		res += A[i] * (m - lastvis);
		if (S.count(A[i]) == 1 || lastvis!=m)flag = 1;
		for (int j = lastvis; j >= 1; j--) {
			if (j == 1 && flag == 0) {
				flag = 1;
				res += A[i];
				if (B[j] == A[i]) {
					if (V[j] == 0) {
						V[j] = 1;
						lastvis--;
					}
				}

			}
			else if (V[j] == 1) {
				res += A[i];
				flag = 1;
			}
			else {
				res += B[j];
				V[j] = 1;
				lastvis--;
				S.insert(B[j]);
				if (B[j] == A[i])flag = 1;
			}
		}
	}
	cout << res << endl;
}