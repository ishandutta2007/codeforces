#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <cmath>
#include <ctime>
#include <stack>
#include <set>
#include <map>
#include <cassert>
#include <memory.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

typedef long long li;
typedef long double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();
//void precalc();

#define FILENAME "change me please"
int main(){
	string s = FILENAME;
#ifdef room210
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//cout<<FILENAME<<endl;
	//assert (s != "change me please");
	clock_t start = clock();
#else
	//freopen(FILENAME ".in", "r", stdin);
	//freopen(FILENAME".out", "w", stdout);
#endif
	cout.sync_with_stdio(0);
	int t = 1;
	//precalc();
	//cout << "done!\n";
	//cin >> t;
	//gen();
	while (t--)
		solve();
	/*
#ifdef room210
	cout<<"\n\n\n"<<(clock() - start) / 1.0 / CLOCKS_PER_SEC<<"\n\n\n";
#endif*/
	return 0;
}

//#define int li

string s[2];

void solve () {
	int n;
	cin >> n;
	cin >> s[0] >> s[1];
	int common = 0, one = 0, two = 0;
	assert(s[0].length() == 2 * n && s[1].length() == 2 * n);
	for (int i = 0; i < 2 * n; ++i) {
		if (s[0][i] == '1' && s[1][i] == '1')
			++common;
		if (s[0][i] == '1' && s[1][i] != '1')
			++one;
		if (s[0][i] != '1' && s[1][i] == '1')
			++two;
	}
	if (common % 2 == 1) {
		if (two == 0) {
			cout << "First\n";
			return;
		}
		--two;
	}

	if ((one == two) || (one + 1 == two)) {
		cout << "Draw\n";
		return;
	}
	if (one > two)
		cout << "First\n";
	if ((one + 1) < two)
		cout << "Second\n";
}