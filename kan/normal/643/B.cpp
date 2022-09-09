#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define pb push_back
#define mp make_pair
#define all(x) begin(x), end(x)
#define fi first
#define se second


vector<int> answer;
int n, k, a, b, c, d;

int main()
{
	scanf("%d%d", &n, &k);
	scanf("%d%d%d%d", &a, &b, &c, &d);
	if (k == n - 1 || k == n || n == 4)
	{
		cout << -1 << endl;
		return 0;
	}
	answer.pb(a);
	answer.pb(d);
	for (int i = 1; i <= n; i++) if (i != a && i != b && i != c && i != d) answer.pb(i);
	answer.pb(c);
	answer.pb(b);
	for (int i = 0; i < n; i++) printf("%d ", answer[i]);
	printf("\n");
	for (int i = n - 2; i < n; i++) printf("%d ", answer[i]);
	for (int i = n - 3; i > 1; i--) printf("%d ", answer[i]);
	for (int i = 0; i < 2; i++) printf("%d ", answer[i]);
	printf("\n");
	return 0;
}