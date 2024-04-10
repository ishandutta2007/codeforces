#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;
const string S[] = {"Vasya", "Petya"};
const int gr[30] = {0,1,2,1,4,3,2,1,5,6,2,1,8,7,5,9,8,7,3,4,7,4,2,1,10,9,3,6,11,12};

int n;


/*char gr[1 << 30];

char gr_serie(int mask) {
	if (gr[mask] != -1) return gr[mask];

	vector<char> v;
	for (int x = 0; x < 30; x++) {
		if (mask & (1 << x)) {
		int newmask = mask ^ (1 << x);
			int cur = x + 1;
			while (cur + (x + 1) <= 30) {
				cur += x + 1;
				newmask &= ((1 << 30) - 1) ^ (1 << (cur - 1));
			}
			v.push_back(gr_serie(newmask));
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < inf; i++) if (!binary_search(v.begin(), v.end(), i)) {
		gr[mask] = i;
		break;
	}
	return gr[mask];
}

void findgr() {
    memset(gr, -1, sizeof(gr));
	gr[0] = 0;
	gr_serie((1 << 30) - 1);
	
	for (int i = 0; i < 30; i++) cout << (int)gr[(1 << i) - 1] << ","; cout << endl;
}*/

bool pr(int x) {
	for (int i = 2; i * i <= x; i++) if (!(x % i)) return 0;
	return 1;
}

int fastsolve() {
	int cur = 0;
	set<int> st;
	for (int i = 2; i * i <= n; i++) if (st.find(i) == st.end()) {
		int k = 0, x = 1;
		while (1LL * x * i <= n) {
			x *= i;
			k++;
			st.insert(x);
		}
		cur ^= gr[k];
	}
	int ost = n - st.size();
	cur ^= (ost & 1);
	return !cur;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> n) cout << S[fastsolve()] << endl;

	return 0;
}