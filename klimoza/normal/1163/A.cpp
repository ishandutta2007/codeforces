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

	int n, m;
	cin >> n >> m;
	int f = n / 2;
	if (m <= f) {
		cout << max(1, m) << endl;
	}
	else {
		cout << f - (m - f) + n % 2 << endl;
	}
	//system("pause");
	return 0;
}