#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
vector<int> ans[303];
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> N;
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=N; j++) {
			if (j&1) cout << (j-1)*N+i << ' ';
			else cout << (j-1)*N + (N+1-i) << ' ';
		}
		cout << '\n';
	}
}