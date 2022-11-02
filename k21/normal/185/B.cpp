#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <iomanip>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define DEBUG(x) cout << ">>> " << #x << " = " << (x) << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0;i<(a);++i)

typedef long long ll;

int main() {
	int S, A, B, C;
	cin >> S >> A >> B >> C;
	int sum = A+B+C;
	if (sum == 0) {
		cout << "0.0 0.0 0.0\n";
		return 0;
	}
	double x = (double)S*A/sum;
	double y = (double)S*B/sum;
	double z = (double)S*C/sum;
	cout.precision(30);
	cout << x << ' ' << y << ' ' << z << endl;
	return 0;
}