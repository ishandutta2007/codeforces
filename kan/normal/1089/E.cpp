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

bool was[10][10];

void finish(int r, int c)
{
	printf(" %c8 h8\n", 'a' + c);
	exit(0);
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("a1");
	int r = 1;
	int c = 0;
	was[r][c] = true;
	for (int row = 1; row <= 8; row++)
	{
		if (row == 8)
		{
			for (int col = 0; col <= 7 && n > 1; col++) if (!was[row][col])
			{
				was[row][col] = true;
				n--;
				printf(" %c%d", 'a' + col, row);
				r = row;
				c = col;
			}
			assert(n == 1);
			printf(" h8\n");
		} else
		{
			for (int col = 7; col >= 0 && n > 2; col--) if (!was[row][col])
			{
				if (n == 3 && col == 7) continue;
				was[row][col] = true;
				n--;
				printf(" %c%d", 'a' + col, row);
				r = row;
				c = col;
			}
			if (n == 2) finish(r, c);
			r++;
			was[r][c] = true;
			printf(" %c%d", 'a' + c, r);
			n--;
			//if (n == 2) finish(r, c);
		}
	}
    return 0;
}