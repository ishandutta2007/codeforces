#include <bits/stdc++.h>

using namespace std;

#define re return
#define fi first
#define se second
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define fill(x,y) memset(x,y,sizeof(x))
#define mp make_pair
#define pb push_back
#define j0 j237849523
#define j1 j5435324
#define y0 y2543
#define y1 y548975
#define prev PREV
#define next NEXT
#define left LEFT
#define right RIGHT

typedef pair<int, int> ii;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef double D;

template<typename T> T abs (T x) { re x < 0 ? -x : x; }
template<typename T> T sqr (T x) { re x * x; }

const double pi = 2 * asin (1.0);

const int maxn = 1000006;
const int MAX = 1000006;

int a[maxn];
int ans[MAX + 5];

int n;

int main () {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		int curans = max(1, ans[a[i]]);
		answer = max(answer, curans);
		for (int j = 2 * a[i]; j <= MAX; j += a[i]) ans[j] = max(ans[j], 1 + curans);
	}
	cout << answer << endl;
}