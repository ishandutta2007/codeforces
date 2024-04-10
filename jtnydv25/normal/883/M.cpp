#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int N = 200005;

int n;

int main() {
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	cout << 2 * (max(2, abs(x1-x2) + 1) + max(2, abs(y1-y2) + 1)) << endl;

	return 0;
}