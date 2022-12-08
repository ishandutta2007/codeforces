#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>

using namespace std;

typedef long long ll;

ll INF = 4e18;
int INFi = 2e9;
double eps = 1e-8;
ll mod = 1e9 + 7;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
		
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vector<int> t1 = { a[0] };
	vector<int> t2;
	int cur = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] == a[i - 1]) {
			cur++;
			if (cur == 2) t2.push_back(a[i]);
			else {
				cout << "NO\n";
				return 0;
			}
		}
		else {
			cur = 1;
			t1.push_back(a[i]);
		}
	}
	sort(t1.begin(), t1.end());
	sort(t2.begin(), t2.end(), cmp);
	cout << "YES\n";
	cout << t1.size() << endl;
	for (int i : t1) cout << i << " ";
	cout << endl;
	cout << t2.size() << endl;
	for (int i : t2) cout << i << " ";
	cout << endl;
	//system("pause");
	return 0;
}