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

char s[500];

int main()
{
	int NT;
	scanf("%d", &NT);
	for (int T =0 ; T < NT; T++)
	{
		scanf("%s", s);
		int n = strlen(s);
		int sum = 0;
		int cnt0 = 0;
		bool waseven = false;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == '0') cnt0++;
			else if ((s[i] - '0') % 2 == 0) waseven = true;
			sum += (s[i] - '0') % 3;
		}
		if (sum % 3 == 0 && cnt0 > 0 && (waseven || cnt0 > 1)) printf("red\n");
		else printf("cyan\n");
	}
    return 0;
}