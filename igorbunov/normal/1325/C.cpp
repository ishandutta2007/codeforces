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

vector<int> g[100000];

map<pair<int, int>, int> m;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
    	int a, b;
    	cin >> a >> b;
    	a--;
    	b--;
    	g[a].push_back(b);
    	g[b].push_back(a);
    	m[make_pair(a, b)] = i;
    	m[make_pair(b, a)] = i;
    }

    vector<int> ans(n - 1, -1);

    for (int i = 0; i < n; i++) {
    	if (g[i].size() >= 3) {
    		for (int j = 0; j < 3; j++) {
    			ans[m[make_pair(i, g[i][j])]] = j;
    		}

    		int kek = 3;
    		for (int j = 0; j < n - 1; j++) {
    			if (ans[j] == -1) {
    				ans[j] = kek;
    				kek++;
    			}
    		}

    		for (int j = 0; j < n - 1; j++) {
    			cout << ans[j] << endl;
    		}

    		cout << endl;
    		return 0;
    	}
    }

    for (int i = 0; i < n - 1; i++) {
    	cout << i << endl;
    }
}