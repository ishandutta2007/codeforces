#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
const int maxn = 505;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<array<int, 2>> a(n);
    for(auto &[x, y] : a) cin >> x >> y;
    for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) if(a[i][0]-a[j][0] && a[i][1]-a[j][1]) {
			cout << abs((a[i][0]-a[j][0])*(a[i][1]-a[j][1])) << '\n';
			return 0;
		}
	cout << -1;
}