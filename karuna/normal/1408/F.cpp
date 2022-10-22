#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;

void solve(int pos, int x, vector<pii> &Q) {
	for (int i=1; i<x; i<<=1) {
		for (int j=pos; j<pos+x; j+=2*i) {
			for (int k=j; k<j+i; k++) Q.emplace_back(k, k+i);
		}
	}
}
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> N;

	vector<pii> Q;
	int x = 1;
	while (2*x <= N) x <<= 1;

	solve(1, x, Q);
	solve(N-x+1, x, Q);

	cout << Q.size() << '\n';
	for (int i=0; i<Q.size(); i++) cout << Q[i].va << ' ' << Q[i].vb << '\n';
}