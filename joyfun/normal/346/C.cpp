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

const int N = 100005;
int n, x[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
	sort(x + 1, x + n + 1);
	n = unique(x + 1, x + n + 1) - x - 1;
	int ans = 0;
	int a, b;
	scanf("%d%d", &a, &b);
	while(a > b){
		while(n > 0 && a - a % x[n] < b) n--;
		int cur = 1;
		for(int i = n; i >= 1; i--) {
			int tmp = a % x[i];
			if(tmp > cur && a - tmp >= b)
				cur = tmp;
			if(cur >= x[i])
				break;
		}
		a -= cur;
		ans++;
	}
	printf("%d\n",ans);
	return 0;
}