#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int main() {
	int n;
	scanf("%d", &n);
	vector <int> v(n);
	rep(i, n) scanf("%d", &v[i]);
	int k = (n - 1) / 2;
	nth_element(v.begin(), v.begin() + k, v.end());
	printf("%d\n", v[k]);
	return 0;
}