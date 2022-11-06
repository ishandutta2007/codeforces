#pragma comment(linker, "/stack:64000000")
#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <algorithm>
#include <iostream>
#include <fstream>
#include <cassert>
#include <iomanip>
#include <utility>
#include <cstring>
#include <complex>
#include <cstdlib>
#include <bitset>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define for1(i, n) for (int i = 1; i <= int(n); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define debug(x) cerr << #x << " = " << x << endl;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair((a), (b))
#define X first
#define Y second
#define ft first
#define sc second

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long double ld;
typedef pair<ld, ld> ptd;
typedef pair <int, int> pt;
typedef long long li;
typedef unsigned char byte;

const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-9;
const int INF = 1000 * 1000 * 1000;

const int N = 100 + 13;

int n;
char bad[N][N];
char res[N];
int len;
int lens[N];
int used[N];
char let;

inline bool occ (int idx, int pos)
{
	forn(i, lens[idx])
		if (tolower(res[pos + i]) != tolower(bad[idx][i]))
			return false;
			
	return true;
}

int main()
{
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	
	cin >> n;
	
	forn(i, n)
	{
		scanf("%s", bad[i]);
		lens[i] = strlen(bad[i]);
	}
		
	scanf("%s", res);
	len = strlen(res);
	
	cin >> let;
	
	forn(i, n)
	{
		forn(j, len)
		{
			if (j + lens[i] > len)
				break;
				
			if (occ(i, j))
				forn(k, lens[i])
					used[j + k] = true;
		}
	}
	
	forn(i, len)
		if (used[i])
		{
			if (tolower(res[i]) == tolower(let))
			{
				if (isupper(res[i]))
					res[i] = 'A' + (tolower(let) == 'a');
				else
					res[i] = 'a' + (tolower(let) == 'a');
			
			} else
			{
				if (isupper(res[i]))
					res[i] = toupper(let);
				else
					res[i] = tolower(let);
			}
		}
		
	puts(res);

	return 0;
}