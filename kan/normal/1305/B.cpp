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

const int maxn = 100005;

char s[maxn];
int n;
vector<int> ansl, ansr;

int main()
{
	scanf("%s", s);
	n = strlen(s);
	int cl = 0;
	int cr = n - 1;
	while (true)
	{
		while (cl < n && s[cl] == ')') cl++;
		while (cr >= 0 && s[cr] == '(') cr--;
		if (cl < cr)
		{
			ansl.pb(cl);
			ansr.pb(cr);
			cl++;
			cr--;
		} else break;
	}
	if (ansl.empty())
	{
		cout << 0 << endl;
	} else
	{
		cout << 1 << endl << (int)ansl.size() * 2 << endl;
		for (auto t : ansl) cout << t + 1 << ' ';
		reverse(all(ansr));
		for (auto t : ansr) cout << t + 1 << ' ';
		cout << endl;
	}
    return 0;
}