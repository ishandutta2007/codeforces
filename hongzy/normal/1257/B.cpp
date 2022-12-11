#include <bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define ucin() ios :: sync_with_stdio(0)
typedef vector<int> vi;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;
typedef double db;

const int N = 1e5 + 10;

int main() {
	ucin();
	int t; cin >> t;
	while(t --) {
		ll x, y;
		cin >> x >> y;
		bool tag = 1;
		if(x == 1) tag = y == 1;
		else {
			if(x == 2 || x == 3) tag = y <= 3;
			else tag = 1;
		}
		cout << (tag ? "YES" : "NO") << endl; 
	}
	return 0;
}