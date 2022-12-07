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

const int N = 2000005;
int n, p[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) p[i] = i;
	for (int i = 2; i <= n; i++) {
		int pr = p[i - 1];
		int j;
		for (j = i - 1 + i; j <= i - 2 + n; j += i) {
			int tmp = p[j];
			p[j] = pr;
			pr = tmp;
		}
		p[i + n - 1] = pr;
		//for (int j = i; j < i + n; j++) printf("%d ", p[j]); printf("\n");
	}
	for (int i = n; i < 2 * n; i++) printf("%d ", p[i]); printf("\n");
	return 0;
}