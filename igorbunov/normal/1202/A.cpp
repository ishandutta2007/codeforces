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
 
#pragma GCC_OPTIMAZE("ofast")
 
using namespace std;
 

#define int long long
#define endl "\n"

signed main() {
	int q;
	cin >> q;
	while (q-->0) {
		string s, t;
		cin >> s >> t;

		reverse(s.begin(), s.end());
		reverse(t.begin(), t.end());

		int n = 0;

		while (t[n] != '1') {
			n++;
		}

		int m = n;
		
		while (s[m] != '1') {
			m++;
		}

		cout << m - n << endl;

	}
}