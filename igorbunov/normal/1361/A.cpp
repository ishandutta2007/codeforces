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

vector<int> g[600000];
bool can = true;
vector<int> arr;
vector<int> used(600000);
vector<int> c(600000);
void dfs(int v) {
	used[v] = 1;
	for (auto u: g[v]) {
		if (c[v] == c[u]) {
			can = false;
		}
		if (c[u] < c[v]) {
			continue;
		}
		if (used[u] == 1) {
			can = false;
			continue;
		}
		if (used[u] == 2) {
			continue;
		}
		dfs(u);
	}
	used[v] = 2;
	arr.push_back(v);
}

vector<bool> kek(600001, 0);


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
    	int a, b;
    	cin >> a >> b;
    	a--;
    	b--;
    	g[a].push_back(b);
    	g[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
    	cin >> c[i];
    }
    for (int i = 0; i < n; i++) {
    	if (used[i] == 0) {
    		dfs(i);
    	}
    }
    if (!can) {
    	cout << -1;
    	return 0;
    }
    reverse(arr.begin(), arr.end());

    vector<int> now(n, -1);
    for (int i = 0; i < n; i++) {
    	int ind = arr[i];
    	for (auto u: g[ind]) {
    		if (now[u] != -1) {
    			kek[now[u]] = true;
    		}
    	}
    	int need = c[ind];
    	if (kek[need]) {
    		cout << -1;
    		return 0;
    	}
    	for (int i1 = 1; i1 < need; i1++) {
    		if (!kek[i1]) {
    			cout << -1;
    			return 0;
    		}
    	}
    	for (auto u: g[ind]) {
    		if (now[u] != -1) {
    			kek[now[u]] = false;
    		}
    	}
    	now[ind] = c[ind];
    }
    for (int i = 0; i < arr.size(); i++) {
    	cout << arr[i] + 1 << " ";
    }

}