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
typedef double ld;
typedef pair<ll, ll> pll;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	//ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

	int h1, a1, c1;
	cin >> h1 >> a1 >> c1;

	int h2, a2;
	cin >> h2 >> a2;

	for (int k = 0; ; ++k) {
		int h = h1 + k * (c1 - a2);
		int u = (h2 + a1 - 1) / a1;
		if ((u - 1) * a2 < h) {
			cout << k + u << "\n";
			for (int i = 0; i < k; ++i) {
				cout << "HEAL\n";
			}
			for (int i = 0; i < u; ++i) {
				cout << "STRIKE\n";
			}
			return 0;
		}
	}

}