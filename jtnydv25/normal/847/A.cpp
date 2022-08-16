#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int N = 105;

int n;
int l[N], r[N];

int main() {
	scanf("%d", &n);
	vi roots;
	for (int i=1; i<=n; i++) {
		scanf("%d%d", l+i, r+i);
		if (l[i] == 0)
			roots.push_back(i);
	}
	int prv;
	while (true) {
		prv = roots.back();
		roots.pop_back();
		for (int i=r[prv]; i; i=r[i]) {
			r[prv] = i;
			prv = i;
		}
		if (!roots.empty()) {
			r[prv] = roots.back();
			l[roots.back()] = prv;
		} else {
			break;
		}
	}

	for (int i=1; i<=n; i++)
		printf("%d %d\n", l[i], r[i]);

	return 0;
}