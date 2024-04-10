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

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
		
	int n;
	cin >> n;
	vector<int> a(n);
	int cnt1 = 0;
	int cnt2 = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] % 2) cnt1++;
		else cnt2++;
	}
	for (int i = 0; i < n; i++) {
		if (a[i] % 2) cnt1--;
		else cnt2--;
		if (!cnt1 || !cnt2) {
			cout << i + 1 << endl;
			return 0;
		}
	}
	//system("pause");
	return 0;
}