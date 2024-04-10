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

int a[4];

int main() {
	for (int i = 0; i < 4; i++) scanf("%d", &a[i]);
	if (a[0] + a[2] == a[1] * 2 && a[1] + a[3] == a[2] * 2)
		printf("%d\n", a[3] * 2 - a[2]);
	else if (a[0] * a[2] == a[1] * a[1] && a[1] * a[3] == a[2] * a[2] && a[3] * a[3] % a[2] == 0)
		printf("%d\n", a[3] * a[3] / a[2]);
	else printf("42\n");
	return 0;
}