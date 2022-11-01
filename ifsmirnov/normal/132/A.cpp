#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
const int maxn = 200500;
#define se second
#define fi first
#define mp make_pair
#define pb push_back
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef double ld;
const int inf = 1e9+100500;
const ld eps = 1e-9;
typedef long long i64;

int a[maxn], n;
i64 s;

char reverse(char t)
{
	char a = 0;
	forn(i, 8) if (t&(1<<i)) a |= (1 << (7-i));
	return a;
}

int main()
{
	string s;
	getline(cin, s);
	
	int last = 0;
	forn(i, s.length())
	{
		cout << (int)((last - reverse(s[i])+256)%256) << endl;
		last = reverse(s[i]);
	}	
	
	return 0;
}