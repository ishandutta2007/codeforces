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

const int maxn = 2000006;

const int LEFT = -1;
const int RIGHT = 1;

int a[maxn];
ll nowsum;
vector<int> answer;
int n, remains;
int curh, willh;

vector<int> solve(int cur)
{
	if (cur > n) return {0};
	vector<int> curans;
	curans.pb(a[cur]);
	auto rl = solve(cur * 2);
	auto rr = solve(cur * 2 + 1);
	if (cur > remains)
	{
		int pl =0;
		int pr = 0;
		while (pl < (int)rl.size() - 1 || pr < (int)rr.size() - 1)
		{
			if (pl < (int)rl.size() - 1 && (pr == (int)rr.size() - 1 || rl[pl] > rr[pr]))
			{
				curans.pb(rl[pl]);
				pl++;
			} else
			{
				curans.pb(rr[pr]);
				pr++;
			}
		}
		curans.pb(0);
		return curans;
	}
	//cout << "merge " << endl;
	//for (auto t : rl) cout << t << ' ';
	//cout << endl;
	//for (auto t : rr) cout << t << ' ';
	//cout << endl;
	int pl = 0;
	int pr = 0;
	int side = 0;
	while (true)
	{
		if (rl[pl] > rr[pr])
		{
			if (pl == (int)rl.size() - 1)
			{
				side = LEFT;
				break;
			}
			curans.pb(rl[pl]);
			pl++;
		} else
		{
			if (pr == (int)rr.size() - 1)
			{
				side = RIGHT;
				break;
			}
			curans.pb(rr[pr]);
			pr++;
		}
	}
	assert(side != 0);
	//curans.pop_back();
	//if (side == LEFT) curans.pb(rl.back());
	//else curans.pb(rr.back());
	while (pr < (int)rr.size() - 1)
	{
		nowsum -= rr[pr];
		answer.pb(cur * 2 + 1);
		pr++;
	}
	while (pl < (int)rl.size() - 1)
	{
		nowsum -= rl[pl];
		answer.pb(cur * 2);
		pl++;
	}
	return curans;
}

void solve()
{
	scanf("%d%d", &curh, &willh);
	//curh = 20;
	//willh = 1;
	n = (1 << curh) - 1;
	remains = (1 << willh) - 1;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	//for (int i = 1; i <= n; i++) a[i] = rng();
	nowsum = accumulate(a + 1, a + n + 1, 0LL);
	answer.clear();
	auto ret = solve(1);
	for (int i = 0; i < (int)ret.size() - 1; i++)
	{
		answer.pb(1);
		nowsum -= ret[i];
	}
	printf("%lld\n", nowsum);
	reverse(all(answer));
	for (auto t : answer) printf("%d ", t);
	printf("\n");
}

int main()
{
	int NT;
	scanf("%d", &NT);
	for (int T = 0; T < NT; T++)
	{
		solve();
	}
    return 0;
}