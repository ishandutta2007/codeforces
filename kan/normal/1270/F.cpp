#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

const int maxn = 200005;
const int maxk = 100;
const int maxdiff = (maxn + maxk) / maxk;

map<int, int> cnt;
int b[maxn];
int wh[maxn];
char s[maxn];
int a[maxn];
int n;

int main()
{
	scanf("%s", s);
	n = strlen(s);
	
	//rng.seed(239);
	//n = 200000;
	//for (int i = 0; i < n; i++) s[i] = '0' + ((int)(rng() % 100) == 0 ? 1 : 0);
	
	b[0] = 0;
	wh[0] = 0;
	for (int i = 0; i < n; i++)
	{
		a[i] = s[i] - '0';
		b[i + 1] = b[i] + a[i];
		if (a[i] == 1) wh[b[i + 1]] = i + 1;
	}
	
	ll answer = 0;
	for (int r = 0; r <= n; r++)
	{
		for (int diff = 1; diff < maxdiff && diff <= b[r]; diff++)
		{
			int L = wh[b[r] - diff];
			int R = wh[b[r] - diff + 1];
			int curmaxk = (r - L) / diff;
			int curmink = maxk;
			curmink = max(curmink, (r - R) / diff + 1);
			//cout << r << ' ' << diff << ' ' << L << ' ' << R << ' ' << curmaxk << ' ' << curmink << endl;
			answer += max(0, curmaxk - curmink + 1);
		}
	}
	//cerr << clock() << endl;
	for (int k = 1; k < maxk; k++)
	{
		cnt.clear();
		for (int r = 0; r <= n; r++)
		{
			int &curcnt = cnt[r - b[r] * k];
			//cout << r << ' ' << k << ' ' << curcnt << endl;
			answer += curcnt;
			curcnt++;
		}
	}
	printf("%lld\n", answer);
    return 0;
}