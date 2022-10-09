#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[200005];

ll pc[200005][4];
bool inst[200005][4];

ll run(int x, int step) {
	if (x < 1 || x > n)
		return 0;
	
	if (inst[x][step] || x == 1)
		return 123123123123123123ll;

	if (pc[x][step] != -1)
		return pc[x][step];

	inst[x][step] = 1;

	if (step == 2) {
		pc[x][step] = run(x + a[x], 3) + a[x];
	} else {
		pc[x][step] = run(x - a[x], 2) + a[x];
	}

	inst[x][step] = 0;
	return pc[x][step];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=2; i<=n; i++)
		cin >> a[i];

	memset(pc, 255, sizeof(pc));

	for (int i=1; i<n; i++) {
		ll z = i + run(1+i, 3);
		if (z >= 123123123123123123ll)
			z = -1;
		cout << z << '\n';
	}
}