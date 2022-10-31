#include <bits/stdc++.h>

using namespace std;
#define DIM 500007
#define INF 10E16
#define MAXN 10000007
#define MODULO 998244353 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pairll;
typedef ll arr[DIM];
typedef pairll parr[DIM];
typedef vector<ll> graph[DIM];

ll a1, a2, a3, a4;
ll A[DIM];
arr B;
// 4, 8, 15, 16, 23,  42
set<ll> S;
arr V;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	A[1] = 4; A[2] = 8;
	A[3] = 15;
	A[4] = 16;
	A[5] = 23;
	A[6] = 42;
	for (int i = 1; i <= 6; i++)S.insert(A[i]);
	cout << "? 1 2" << endl;
	cin >> a1;
	ll ar = a1;
	for (int i = 1; i <= 6; i++) {
		for (int j = 2; j <= 6; j++) {
			if (A[i] * A[j] == a1) {
				V[A[i]]++;
				V[A[j]]++;
			}
		}
	}
	cout << "? 1 3" << endl;
	cin >> a2;
	a1 = a2;
	for (int i = 1; i <= 6; i++) {
		for (int j = 2; j <= 6; j++) {
			if (A[i] * A[j] == a1) {
				V[A[i]]++;
				V[A[j]]++;
			}
		}
	}
	cout << "? 1 4" << endl;
	cin >> a3;
	a1 = a3;
	for (int i = 1; i <= 6; i++) {
		for (int j = 2; j <= 6; j++) {
			if (A[i] * A[j] == a1) {
				V[A[i]]++;
				V[A[j]]++;
			}
		}
	}
	cout << "? 1 5" << endl;
	cin >> a4;
	a1 = a4;
	for (int i = 1; i <= 6; i++) {
		for (int j = 2; j <= 6; j++) {
			if (A[i] * A[j] == a1) {
				V[A[i]]++;
				V[A[j]]++;
			}
		}
	}
	ll mx=0, num;
	for (int i = 1; i <= 6; i++) {
		if (V[A[i]] > mx) {
			mx = V[A[i]];
			num = A[i];
		}
	}
	a1 = ar;
	B[1] = num;
	B[2] = a1 / num;
	B[3] = a2 / num;
	B[4] = a3 / num;
	B[5] = a4 / num;
	for (int i = 1; i <= 6; i++) {
		ll flag = 0;
		for (int j = 1; j <= 5; j++) {
			if (A[i] == B[j]) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			num = A[i];
			break;
		}
	}
	B[6] = num;
	cout << '!'<<' ';
	for (int i = 1; i <= 6; i++) {
		cout << B[i] << ' ';
	}
	cout << endl;
}