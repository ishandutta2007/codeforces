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
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    vector<int> arr(26);
    int ans = 1;
    for (int i = 0; i < s.size(); i++) {
    	arr[s[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
    	ans = max(ans, arr[i]);
    }

    for (int i = 0; i < 26; i++) {
    	for (int j = 0; j < 26; j++) {
    		char a = (char)('a' + i);
    		char b = (char)('a' + j);
    		int kek = 0;
    		for (int k = 0; k < s.size(); k++) {
    			kek += (s[k] == b);

    		}
    		int now = 0;
    		for (int k = 0; k < s.size(); k++) {
    			kek -= (s[k] == b);
    			if (s[k] == a) {
    				now += kek;
    			}
    		}
    		ans = max(ans, now);
    	}
    }
    cout << ans;
}