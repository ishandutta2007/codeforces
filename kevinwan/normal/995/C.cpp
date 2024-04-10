#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int mov[100000];
pair<pair<ll,ll>, int> in[100000];
int n;
bool randomsort(const pair<pair<ll, ll>, int> &a, const pair<pair<ll, ll>, int> &b) { return rand() & 1; }
ll dist(ll a, ll b) { return a * a + b * b; }
bool solve() {
	random_shuffle(in, in + n);
	ll curx=0, cury=0;
	int i;
	for (i = 0; i < n; i++) {
		if (dist(curx + in[i].first.first, cury + in[i].first.second) <= dist(curx - in[i].first.first, cury - in[i].first.second))mov[in[i].second] = 1, curx += in[i].first.first, cury += in[i].first.second;
		else mov[in[i].second] = -1, curx -= in[i].first.first, cury -= in[i].first.second;
	}
	if (dist(curx, cury) > dist(1500000, 0))return 1;
	for (i = 0; i < n; i++)printf("%d ", mov[i]);
	getchar(); getchar();
	return 0;
}
int main() {
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++)scanf("%lld%lld", &in[i].first.first, &in[i].first.second), in[i].second = i;
	while (solve());
}