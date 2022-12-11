#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define fs first
#define sc second
#define ucin() ios :: sync_with_stdio(0)

typedef map<int, int> mii;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const int N = 110;

int n, m, k, a[N];

int main() {
	int te;
	scanf("%d", &te);
	while(te --) {
		scanf("%d%d%d", &n, &m, &k);
		for(int i = 1; i <= n; i ++) scanf("%d", a + i);
		bool fail = 0;
		for(int i = 1; i < n; i ++) {
			if(a[i] >= a[i + 1] - k) {
				int c = min(a[i] - (a[i + 1] - k), a[i]);
				a[i] -= c; m += c;
			}
			if(a[i] < a[i + 1] - k) {
				int c = a[i + 1] - k - a[i];
				a[i] += c; m -= c;
				if(m < 0) {
					fail = 1; break ;
				}
			}
		}
		puts(fail ? "NO" : "YES");
	}
	return 0;
}