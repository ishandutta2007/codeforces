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
using namespace std;
  
#define int long long
#define endl '\n'

int32_t main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> pref(n + 1, vector<int>(26, 0));
    for (int i = 1; i <= n; i++) {
    	for (int j = 0; j < 26; j++) {
    		pref[i][j] = (pref[i - 1][j] + (s[i - 1] == ('a' + j)));
    	}
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
    	string t;
    	cin >> t;
    	vector<int> now(26);
    	for (int j = 0; j < t.size(); j++) {
    		now[t[j] - 'a']++;
    	}
    	int l = 0;
    	int r = n;
    	while (r - l > 1) {
    		int m = (l + r) / 2;
    		bool can = true;
    		for (int j = 0; j < 26; j++) {
    			if (pref[m][j] < now[j]) {
    				can = false;
    				break;
    			}
    		}
    		if (can) {
    			r = m;
    		} else {
    			l = m;
    		}
    	}
    	cout << r << endl;
    }
}