#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>
#include <cassert>

using namespace std;

#define PI 3.14159265
typedef long long ll;

const ll INF = 1e18;
ll mod = 1e9 + 7;


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	
	vector<ll> a(4);
	for (int i = 0; i < 4; i++) cin >> a[i];
	sort(a.begin(), a.end());
	ll f1 = a[2] + a[0] - a[3];
	ll f2 = a[0] - f1;
	ll f3 = a[2] - f1;
	cout << f1 << " " << f2 << " " << f3 << endl;
	//system("pause");
	return 0;
}