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
 
#pragma GCC_OPTIMIZE("ofast")
 
using namespace std;
 

#define int long long
#define endl "\n"
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    map<string, int> kek;

    int ans = 0;

    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
    	cin >> arr[i];
    	kek[arr[i]]++;
    }

    for (int i = 0; i < n; i++) {
    	for (int j = i + 1; j < n; j++) {
    		string s1 = arr[i];
    		string s2 = arr[j];
    		string s3;

    		for (int l = 0; l < k; l++) {
    			if (s1[l] == s2[l]) {
    				s3.push_back(s1[l]);
    			} else {
    				if (s1[l] != 'S' && s2[l] != 'S') {
    					s3.push_back('S');
    				}

    				if (s1[l] != 'E' && s2[l] != 'E') {
    					s3.push_back('E');
    				}

    				if (s1[l] != 'T' && s2[l] != 'T') {
    					s3.push_back('T');
    				}
    			}
    		}

    		ans += kek[s3];

    		if (s3 == s1) {
    			ans--;
    		}
    		if (s3 == s2) {
    			ans--;
    		}
    	}
    }

    cout << ans / 3 << endl;
}