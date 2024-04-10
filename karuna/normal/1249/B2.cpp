#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAX = 2e5+1;
int Q, N;
int A[MAX], P[MAX], sz[MAX];

int Find(int a) {
	if (P[a] == a) return a;
	return P[a] = Find(P[a]);
}
void Union(int a, int b) {
	if (Find(a) == Find(b)) return;
	sz[Find(a)] += sz[Find(b)];
	P[Find(b)] = Find(a);
}
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> Q;
	while (Q--) {
		cin >> N;
		for (int i=1; i<=N; i++) P[i] = i, sz[i] = 1;
		for (int i=1; i<=N; i++) {
			int x; cin >> x;
			Union(i, x);
		}
		for (int i=1; i<=N; i++) cout << sz[Find(i)] << ' ';
		cout << '\n';
	}
}