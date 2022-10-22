#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N, K, x, y;
int parent[101010];
int cnt[101010];
vector<int> v[101010];

int Find(int a) {
	if (parent[a] == a) return a;
	return parent[a] = Find(parent[a]);
}
void Union(int a, int b) {
	if (Find(a) == Find(b)) return;
	parent[Find(b)] = Find(a);
	return;
}

int main() {
	cin >> N >> K;
	for (int i=1; i<=N; i++) parent[i] = i;
	for (int i=0; i<K; i++) {
		cin >> x >> y; Union(x, y);
	}

	for (int i=1; i<=N; i++)
		cnt[Find(i)]++;

	int mx = 0;
	for (int i=1; i<=N; i++)
		if (cnt[i] != 0) mx += cnt[i]-1;

	cout << K-mx;
}