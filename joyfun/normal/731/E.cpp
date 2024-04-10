#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()

const int N = 200005;
int n, s[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &s[i]), s[i] += s[i - 1];
	int f = s[n];
	for (int i = n - 1; i >= 2; i--) f = max(s[i] - f, f);
	printf("%d\n", f);
	return 0;
}