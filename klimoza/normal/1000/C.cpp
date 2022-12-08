#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>
#include <cassert>
#include <math.h>
#include <random>

using namespace std;

#define PI 3.14159265
typedef long long ll;

const ll INF = 4 * 1e18;
const int INFi = 2 * 1e9;
ll mod = 1e9 + 7;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	vector<ll> cnt(n + 1);
	vector<pair<ll, ll>> tim;
	tim.push_back({ 0, -2 });
	ll t1, t2;
	for (int i = 0; i < n; i++) {
		cin >> t1 >> t2;
		tim.push_back({ t1, 1 });
		tim.push_back({ t2 + 1, -1 });
	}
	sort(tim.begin(), tim.end());
	ll cur = 0;
	for (int i = 1; i <= 2 * n; i++) {
		cnt[cur] += tim[i].first - tim[i - 1].first;
		cur += tim[i].second;
		//cout << tim[i].first << " " << tim[i].second << " " << cur << endl;
	}
	for (int i = 1; i <= n; i++) cout << cnt[i] << " ";
	cout << endl;
	//system("pause");
	return 0;
}