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

int n;
int need = 0;

vector <int> got;
int filled = 0;
int had = 0;

vector <vector<int> > can;

void rec () {
	if (had > 6)
		return;
	if (filled == need)
		can.push_back(got);
	for (int num = 0; num < 10; ++num) 
		if (need & (1 << num)){
			got.push_back(num);
			++had;
			bool f = true;
			if (filled & (1 << num))
				f = false;
			if (f) {
				filled |= (1 << num);
			}

			rec();

			--had;
			got.pop_back();
			if (f) {
				filled ^= (1 << num);
			}
		}
}

bool good (vector<int>& now) {
	if (now.size() == 0)
		return false;
	if (now.size() == 1)
		return true;
	if (now[0] == 0)
		return false;
	int cur = 0;
	for (int i = 0; i < now.size(); ++i)
		cur = cur * 10 + now[i];
	return cur < 256;
}

void solve () {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int cur; cin >> cur;
		need |= (1 << cur);
	}

	rec();

	//cout << can.size() << "\n";

	vector<vector <int> > palindromes;
	for (int i = 0; i < can.size(); ++i) {
		vector<int> now = can[i];
		vector <int> nex = can[i];
		for (int i = now.size() - 1; i >= 0; --i)
			nex.push_back(now[i]);
		palindromes.push_back(nex);
		nex = can[i];
		for (int i = (int)now.size() - 2; i >= 0; --i)
			nex.push_back(now[i]);
		palindromes.push_back(nex);
	}

	//cout << palindromes.size() << endl;

	vector <vector<vector<int> > > res;

	for (int i = 0; i < palindromes.size(); ++i) {
		int a[3];
		vector <int> now = palindromes[i];
		vector <int> first, second, third;
		for (a[0] = 0; a[0] < now.size(); ++a[0]) {
			first.push_back(now[a[0]]);
			if (!good(first)) {
				break;
			}
			second.clear();
			for (a[1] = a[0] + 1; a[1] < now.size(); ++a[1]) {
				second.push_back(now[a[1]]);
				if (!good(second)) {
					break;
				}
				third.clear();
				for (a[2] = a[1] + 1; a[2] < now.size(); ++a[2]) {
					third.push_back(now[a[2]]);
					if (!good(third))
						break;
					vector <int> fourth;
					for (int j = a[2] + 1; j < now.size(); ++j)
						fourth.push_back(now[j]);
					if (good(fourth)) {
						vector <vector <int> > add;
						add.push_back(first);
						add.push_back(second);
						add.push_back(third);
						add.push_back(fourth);
						res.push_back(add);
						
					}
				}
			}
		}
	}

	cout << res.size() << "\n";

	for (int i = 0; i < res.size(); ++i) {
		for (int w = 0; w < 4; ++w) {
			for (int j = 0; j < res[i][w].size(); ++j)
				cout << res[i][w][j];
			if (w != 3)
				cout <<".";
		}
		cout << "\n";
	}

}