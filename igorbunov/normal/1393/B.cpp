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
    int n;
    cin >> n;
    vector<int> arr(100007);
    int a = 0, b = 0, c = 0, d = 0;
    for (int i = 0; i < n; i++) {
    	int c3;
    	cin >> c3;
    	if (arr[c3] == 1) {
    		a++;
    	}
    	if (arr[c3] == 3) {
    		b++;
    		a--;
    	}
    	if (arr[c3] == 5) {
    		c++;
    		b--;
    	}
    	if (arr[c3] == 7) {
            d++;
            c--;
    	}
    	arr[c3]++;
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
    	char c1;
    	cin >> c1;
    	if (c1 == '-') {
    		int x;
    		cin >> x;
    		if (arr[x] == 2) {
    			a--;
    		}
    		if (arr[x] == 4) {
    			b--;
    			a++;
    		}
    		if (arr[x] == 6) {
    			c--;
    			b++;
    		}
    		if (arr[x] == 8) {
    			d--;
    			c++;
    		}
    		arr[x]--;
    	} else {
    	    int x;
    	    cin >> x;
    		if (arr[x] == 1) {
    			a++;
	    	}
	    	if (arr[x] == 3) {
	    		b++;
	    		a--;
	    	}
	    	if (arr[x] == 5) {
	    		c++;
	    		b--;
	    	}
	    	if (arr[x] == 7) {
    			d++;
    			c--;
    		}
    		arr[x]++;
    	}
    	//cout << a << " " << b << " " << c << " " << d << endl;
    	if (d) {
    		cout << "YES\n";
    	} else {
    		if (b + c > 1) {
    			cout << "YES\n";
    		} else {
    			if (c > 0 && c + a > 1) {
    				cout << "YES\n";
    			} else {
    				if (b > 0 && b + a > 2) {
    					cout << "YES\n";
    				} else {
    					cout << "NO\n";
    				}
    			}
    		}
    	}
    }
}