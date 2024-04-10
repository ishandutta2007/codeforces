#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
using namespace std;

int n;
int a[100005];
vector<int> e[100005];
int v[100005];

void dfs(int x) {
	v[x] = 1;
	for (int y : e[x]) {
		if (!v[y]) {
			dfs(y);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		e[i].push_back(a[i]);
		e[a[i]].push_back(i);
	}

	int c=0;
	for (int i=1; i<=n; i++) {
		if (!v[i]) {
			dfs(i);
			c++;
		}
	}

	cout << c;


}