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

const int N = 1005;
int n;
char s[N];

int get(int f) {
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] != (f^(i%2)) + '0') ans++;
	}
	return ans;
}

int main() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	printf("%d\n", min(get(0), get(1)));
	return 0;
}