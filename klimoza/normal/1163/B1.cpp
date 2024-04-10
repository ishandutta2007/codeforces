#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <random>

using namespace std;

typedef long long ll;

ll INF = 1e18;
int INFi = 2e9;
double eps = 1e-8;
ll mod = 1e9 + 7;
int p = 47;

int main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> u(n);
	vector<int> col(1e5 + 1);
	vector<bool> used(1e5 + 1);
	vector<int> types(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> u[i];
		used[u[i]] = true;
		col[u[i]]++;
	}
	set<int> f;
	for (int i = 0; i <= 1e5; i++) {
		if (used[i]) {
			types[col[i]]++;
			f.insert(col[i]);
		}
	}
	int sz = f.size();
	for (int i = n; i > 0; i--) {
		//cout << i << " " << sz << " " << endl;
		if (sz == 2) {
			int h = col[u[i - 1]];
			if (types[h + 1] == 1 || (types[h] == 1 && types[h - 1] != 0) || (types[1] == 1)) {
				cout << i << endl;
				//system("pause");
				return 0;
			}
		}
		else if ((sz == 1 && types[1] != 0) || (sz == 1 && types[col[u[i - 1]]] == 1)) {
			cout << i << endl;
			//system("pause");
			return 0;
		}
		types[col[u[i - 1]]]--;
		col[u[i - 1]]--;
		if (types[col[u[i - 1]] + 1] == 0) sz--;
		types[col[u[i - 1]]]++;
		if (types[col[u[i - 1]]] == 1 && col[u[i - 1]] != 0) sz++;
	}
	cout << 0 << endl;
	//system("pause");
	return 0;
}