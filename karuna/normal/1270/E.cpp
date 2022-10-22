#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
pii A[1010];
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> N;

	int mnx=0, mny=0;
	for (int i=0; i<N; i++) {
		cin >> A[i].va >> A[i].vb;
		mnx = min(mnx, A[i].va);
		mny = min(mny, A[i].vb);
	}

	for (int i=0; i<N; i++) {
		A[i].va -= mnx-1;
		A[i].vb -= mny-1;
	}

	while (1) {
		vector<int> B[4];

		for (int i=0; i<N; i++) {
			int idx = 2*(A[i].va&1) + (A[i].vb&1);
			B[idx].push_back(i+1);
		}

		int sz[4];
		for (int i=0; i<4; i++) sz[i] = B[i].size();

		if (sz[0] == N || sz[1] == N || sz[2] == N || sz[3] == N) {
			for (int i=0; i<N; i++) A[i].va>>=1, A[i].vb>>=1;
			continue;
		}

		if (sz[0]+sz[3] != 0 && sz[1]+sz[2] != 0) {
			cout << sz[0]+sz[3] << '\n';
			for (auto x : B[0]) cout << x << ' ';
			for (auto x : B[3]) cout << x << ' ';
			break;
 		}
 		if (sz[0]+sz[3] != 0) {
 			cout << sz[0] << '\n';
			for (auto x : B[0]) cout << x << ' ';
			break;
 		}
 		if (sz[1]+sz[2] != 0) {
 			cout << sz[1] << '\n';
			for (auto x : B[1]) cout << x << ' ';
			break;
 		}
	}

}