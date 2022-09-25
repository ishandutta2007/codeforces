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
#include <cassert>
#include <ctime>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;

int n;
int a[maxn];
set<int> st;

void add(int x) {
	if (st.find(x) == st.end()) st.insert(x);
	else {
		st.erase(x);
		add(x + 1);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> n) {
		st.clear();
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			add(x);
		}
		set<int> :: iterator it = st.end(); it--;
		cout << *it - (int)st.size() + 1 << endl;
	}

	return 0;
}