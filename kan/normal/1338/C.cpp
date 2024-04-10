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

bool was[maxn];
int nn;
ll res;

void out2(int x)
{
	nn--;
	if (nn == 0)
	{
		res = x;
		//printf("%d\n", x);
	}
	//while (x)
	//{
		//printf("%d", x % 2);
		//x /= 2;
	//}
	//printf("\n");
}

ll brute(ll n)
{
	nn = n;
	memset(was, 0, sizeof was);
	res = -1;
	for (int IT = 0; IT < 500 && res == -1; IT++)
	{
		int x = 1;
		while (was[x]) x++;
		for (int y = x + 1; ; y++) if (!was[y] && !was[x ^ y])
		{
			out2(x);
			out2(y);
			out2(x ^ y);
			//printf("\n");
			was[x] = true;
			was[y] = true;
			was[x ^ y] = true;
			break;
		}
	}
	return res;
}

const int table[4][3] = {{0, 0, 0}, {1, 2, 3}, {2, 3, 1}, {3, 1, 2}};

ll answer;

void putd(int p, int m4, int m3)
{
	answer |= (ll)table[m4][m3] << (2 * p);
}

ll solve(ll n)
{
	//nn = n;
	//brute();
	int nm3 = (n - 1) % 3;
	n = (n + 2) / 3;
	n--;
	ll p4 = 1;
	int len = 0;
	while (n >= p4)
	{
		n -= p4;
		p4 *= 4;
		len++;
	}
	answer = 0;
	int curp = 0;
	for (int i = 0; i < len; i++)
	{
		putd(curp, n % 4, nm3);
		n /= 4;
		curp++;
	}
	putd(curp, 1, nm3);
	return answer;
	//printf("%lld\n", answer);
}

int main()
{
	//brute(15);
	//return 0;
	//for (int i = 1; i <= 1000; i++)
	//{
		//cout << i << ' ' << brute(i) << ' ' << solve(i) << endl;
		//assert(brute(i) == solve(i));
	//}
	//brute();
	int NT;
	scanf("%d", &NT);
	for (int T = 0; T < NT; T++)
	{
		ll n;
		scanf("%lld", &n);
		printf("%lld\n", solve(n));
	}
    return 0;
}