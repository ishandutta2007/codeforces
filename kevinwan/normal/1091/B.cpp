#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const ll mod = 998244353;
const int mn = 1005;
pii o[mn], c[mn];
bool comp(const pii&a, const pii&b) { if (a.first < b.first)return 1; if (a.first == b.first&&a.second < b.second)return 1; return 0; }
bool comp2(const pii&a, const pii&b) { return !comp(a, b); }
int main() {
	int n,i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)scanf("%d%d", &o[i].first, &o[i].second);
	for (i = 0; i < n; i++)scanf("%d%d", &c[i].first, &c[i].second);
	sort(o, o + n, comp);
	sort(c, c + n, comp2);
	printf("%d %d", o[0].first + c[0].first, o[0].second + c[0].second);
}