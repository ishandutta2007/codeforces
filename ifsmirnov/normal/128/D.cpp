#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <string>
#include <ctime>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
#define fi first
#define se second
#define mp make_pair
const int maxn = 100500;
typedef pair<int, int> pii;

int n;
int m;
int in[maxn];
int a[maxn];

void scan()
{
	cin >> n;
	forn(i, n) cin >> in[i];
}
bool solve()
{
	sort(in, in+n);
	forn(i, n-1) in[i+1] -= in[0];
	in[0] = 0;
	//forn(i, n) cout << in[i] << " ";
	//cout << endl;
	if (in[n-1] > n+0) return false;
	m = in[n-1]+1;
	forn(i, n)
		a[in[i]]++;
	if (n%2) return false;
	//forn(i, m) cout << a[i] << " ";
	//cout << endl;
	forn(i, m)
	{
		if (i == m-2)
			return a[i] == a[i+1];
		else
		{
			if (a[i] + 1 > a[i+1])
				return false;
			a[i+1] -= a[i];
		}
	}
	return true;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	
	scan();
	cout << (solve() ? "YES" : "NO") << endl;
	
	return 0;
}