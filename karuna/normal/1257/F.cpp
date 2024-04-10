#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N;
int A[201];
map<vector<int>, int> mp;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> N;
	for (int i=0; i<N; i++) cin >> A[i];
	for (int i=N; i<2*N; i++) {
		A[i] = A[i-N]>>15;
		A[i-N] %= 1<<15;
	}

	for (int i=0; i<(1<<15); i++) {
		vector<int> v(N);
		for (int j=0; j<N; j++) {
			int x = A[j] ^ i;
			for (int k=0; k<15; k++) v[j] += (x>>k&1);
		}

		int mn = 15;
		for (int j=0; j<N; j++) mn = min(mn, v[j]);
		for (int j=0; j<N; j++) v[j] -= mn;

		if (mp.find(v) == mp.end()) mp[v] = i;
	}


	int ans=-1;
	for (int i=0; i<(1<<15); i++) {
		vector<int> v(N);
		for (int j=0; j<N; j++) {
			int x = A[j+N] ^ i;
			for (int k=0; k<15; k++) v[j] += (x>>k&1);
		}

		int mx = 0;
		for (int j=0; j<N; j++) mx = max(mx, v[j]);
		for (int j=0; j<N; j++) v[j] = mx-v[j];

		if (mp.find(v) != mp.end()) {
			ans = mp[v] + (i<<15);
			break;
		}
	}
	cout << ans;
}