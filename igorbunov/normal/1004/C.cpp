#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <exception>
#include <stdexcept>

#define int long long

using namespace std;



signed main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	set<int> s;
	vector<int> c(100001, 0);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		s.insert(arr[i]);
		c[arr[i]]++;
	}
	int ans = 0;
	set<int> numbers;
	for (int i = 0; i < n; i++) {
		c[arr[i]]--;
		if (!c[arr[i]]) {
			s.erase(arr[i]);
		}
		if (numbers.size() && numbers.find(arr[i]) != numbers.end()) {
			continue;
		}
		numbers.insert(arr[i]);
		ans += s.size();
	}
	cout << ans;
	return 0;
}