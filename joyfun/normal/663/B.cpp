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

int n;
char str[105];
map<int, int> vis;

int main() {
	scanf("%d", &n);
	while (n--) {
		vis.clear();
		scanf("%s", str);
		int len = strlen(str);
		int s = 1, b = 0;
		for (int j = len - 1; j >= 4; j--) {
			b += (str[j] - '0') * s;
			s *= 10;
			int yu = 1989 % s;
			int h = 1989 / s;
			while (1) {
				int tmp = h * s + b;
				if (tmp >= 1989 && !vis[tmp]) break;
				h++;
			}
			int tmp = h * s + b; vis[tmp] = 1;
			if (j == 4) printf("%d\n", tmp);
		}
	}
	return 0;
}