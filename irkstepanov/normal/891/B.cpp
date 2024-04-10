#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <deque>
#include <memory.h>
#include <assert.h>
#include <cstring>
#include <cmath>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;

const int inf = 1e9;

bool bit(int mask, int pos) {
	return (mask >> pos) & 1;
}

//mt19937 rr(random_device{}());

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	//ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	vector<int> a(n);
	set<int> setik;
	vector<pii> b;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		b.pb({a[i], i});
	}
	sort(all(b));
	vector<int> ans(n);
	for (int i = 0; i < n; ++i) {
		ans[b[i].second] = b[(i + 1) % n].first;
	}

	for (int i = 0; i < n; ++i) {
		cout << ans[i] << " ";
	}
	cout << "\n";

}