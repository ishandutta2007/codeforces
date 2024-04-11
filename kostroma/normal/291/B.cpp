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
	//cout.sync_with_stdio(0);
	int t = 1;
	//precalc();
	//cout << "done!\n";
	//cin >> t;
	//gen();
	while (t--)
		solve();
#ifdef room210
	cout<<"\n\n\n"<<(clock() - start) / 1.0 / CLOCKS_PER_SEC<<"\n\n\n";
#endif
	return 0;
}

//#define int li

char s[100500];

void solve () {
	int bal = 0;
	gets(s);
	string cur;
	int len = strlen(s);
	int been = 0;
	for (int i = 0; i < len; ++i) {
		if (s[i] == ' ' && bal == 0) {
			if (!been)
				continue;
			cout << "<" << cur << ">\n";
			cur.clear();
			been = 0;
			continue;
		}
		been = 1;
		if (s[i] == '"') {
			bal ^= 1;
		}
		if (s[i] != '"')
			cur += s[i];
	}

	if (been)
		cout <<"<" << cur << ">"<<"\n";

}