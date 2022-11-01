#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
typedef double ld;
#define se second
#define fi first
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define unq(x) {sort(all(x));(x).resize(unique(all(x))-(x).begin());}
#define lb lower_bound
const int inf = 1e9+100500;
const int maxn = 100500;
const int mod = 1000000007;
int madd (int x, int y) {return ((x+y)%mod+mod)%mod;}
int mmul (int x, int y) {return ((i64)x*y%mod+mod)%mod;}
int mpow (int x, int k)
{
	if (k == 0) return 1;
	int t = mpow(x, k/2);
	return mmul(mmul(t, t), k%2 ? x : 1);
}
int mdiv (int x, int y) {return mmul(x, mpow(y, mod-2));}

bool prime (int x)
{
	for (int i = 2; i * i <= x; i++)
		if (x%i == 0) return false;
	return true;
}

void factorize(int x, vector<int> &a)
{
	int _x = x;
	for (int i = 2; i*i <= _x; i++)
	{
		if (x%i == 0)
		{
			a.pb(i);
			while (x%i == 0)
				x /= i;
		}
	}
	if (x != 1)
		a.pb(x);
}

vector<int> pr[maxn];
bool b[maxn];
int bp[maxn];

int main()
{
	//freopen("input.txt", "r", stdin);
	
	int n, m;
	scanf("%d%d", &n, &m);
	fore(i, 1, n)
		factorize(i, pr[i]);
	
	forn(i, m)
	{
		char s[10];
		int x;
		scanf("%s%d", s, &x);
		if (s[0] == '+')
		{
			if (b[x])
			{
				printf("Already on\n");
				continue;
			}
			bool fail = 0;
			forn(i, pr[x].size())
				if (bp[pr[x][i]])
				{
					printf("Conflict with %d\n", bp[pr[x][i]]);
					fail = 1;
					break;
				}
			if (!fail)
			{
				b[x] = 1;
				printf("Success\n");
				forn(i, pr[x].size())
					bp[pr[x][i]] = x;
			}
		}
		else
		{
			if (!b[x])
			{
				printf("Already off\n");
				continue;
			}
			b[x] = 0;
			printf("Success\n");
			forn(i, pr[x].size())
				bp[pr[x][i]] = 0;
		}
	}
	
	return 0;
}