#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <algorithm>
#include <set>
#include <list>
#include <map>
#include <string>
#include <queue>
#include <cmath>
#include <cassert>
using namespace std;

#define forn(i, n) for (int i = 0; i < int (n); i++)
#define for1(i, n) for (int i = 1; i <= int (n); i++)
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define sqr(a) ((a) * (a))

typedef long long li;
typedef pair <int, int> pt;
const int INF = 1e9;
const int NMAX = 1e4;
const double EPS = 1e-9;
 
string pat, a, b, tmp;

bool forw () {
	int k = pat.find(a);
	if (k < 0) return false;
	pat.erase(0, k + (int) a.size());
	k = pat.find(b);
	if (k < 0) return false;
	return true;
}

int main()
{
	cin >> pat >> a >> b;
	tmp = pat;
	bool fw = forw();
	pat = tmp;
	reverse(pat.begin(), pat.end());
	bool bc = forw();
	if (fw && bc) cout << "both"; else 
		if (fw) cout << "forward"; else 
			if (bc) cout << "backward"; else cout << "fantasy";
	cout << endl;
	return 0;
}