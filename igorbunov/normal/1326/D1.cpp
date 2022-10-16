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

 
//#pragma GCC_OPTIMIZE("ofast")
using namespace std;


#define int long long
#define endl "\n"

void solve() {
	string s;
	cin >> s;
	int n = s.size();

	vector<int> d1 (n);
	int l=0, r=-1;
	for (int i=0; i<n; ++i) {
	  int k = i>r ? 1 : min (d1[l+r-i], r-i+1);
	  while (i+k < n && i-k >= 0 && s[i+k] == s[i-k])  ++k;
	  d1[i] = k;
	  if (i+k-1 > r)
	    l = i-k+1,  r = i+k-1;
	}

	vector<int> d2 (n);
	l=0, r=-1;
	for (int i=0; i<n; ++i) {
	  int k = i>r ? 0 : min (d2[l+r-i+1], r-i+1);
	  while (i+k < n && i-k-1 >= 0 && s[i+k] == s[i-k-1])  ++k;
	  d2[i] = k;
	  if (i+k-1 > r)
	    l = i-k,  r = i+k-1;
	}

	/*for (int i = 0; i < n; i++) {
		cout << d1[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < n; i++) {
		cout << d2[i] << " ";
	}

	cout << endl;*/
	/*vector<int> ansl(n);
	vector<int> ansr(n);
	for (int i = 0; i < n; i++) {
		int ind = i - d1[i] + 1;
		int val = d1[i] * 2 - 1;
		ansl[ind] = max(ansl[ind], val);
		ind = i + d1[i] - 1;
		ansr[ind] = max(ansr[ind], val);
	}

	for (int i = 1; i < n; i++) {
		int ind = i - d2[i];
		int val = d2[i] * 2;
		ansl[ind] = max(ansl[ind], val);
		ind = i + d2[i];
		ansr[ind] = max(ansr[ind], val);
	}
	int ans = max(ansl[0], ansr[n - 1]);*/
	int ind1 = 0;
	int ind2 = n - 1;
	int now = 0;
	while (ind1 <= ind2 && s[ind1] == s[ind2]) {
		now++;
		ind1++;
		ind2--;
		if (ind1 >= ind2) {
			cout << s << endl;
			return;
		}
	}
	//cout << now << endl;

	int ans = 0;
	int ansp = 0;
	int anss = 0;
	for (int i = 0; i < n; i++) {
		if (d1[i] == 0) {
			continue;
		}
		int l = i - d1[i] + 1;
		int r = i + d1[i] - 1;
		if (l <= n - 1 - r) {
			if (now >= l) {
				if (ans < now * 2 + d1[i] * 2 - 1) {
					ansp = r;
					anss = n - l;
					ans = l * 2 + d1[i] * 2 - 1;
				}
			}
		} else {
			if (now >= n - 1 - r) {
				if (ans < (n - 1 - r) * 2 + d1[i] * 2 - 1) {
					ansp = n - 1 - r - 1;
					anss = l;
					ans = (n - 1 - r) * 2 + d1[i] * 2 - 1;
				}
			}
		}
	}


	for (int i = 1; i < n; i++) {
		if (d2[i] == 0) {
			continue;
		}
		int l = i - d2[i];
		int r = i + d2[i] - 1;
		if (l <= n - 1 - r) {
			if (now >= l) {
				if (ans < l * 2 + d2[i] * 2) {
					ansp = r;
					anss = n - l;
					ans = l * 2 + d2[i] * 2;
				}
			}
		} else {
			if (now >= n - 1 - r) {
				if (ans < (n - 1 - r) * 2 + d2[i] * 2) {
					ansp = n - 1 - r - 1;
					anss = l;
					ans = (n - 1 - r) * 2 + d2[i] * 2;
				}
			}
		}
	}

	for (int i = 0; i <= ansp; i++) {
		cout << s[i];
	}
	for (int i = anss; i < n; i++) {
		cout << s[i];
	}

	cout << endl;

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
    	solve();
    }
}