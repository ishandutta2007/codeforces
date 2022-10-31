#include <iostream>
#include <cstring>
using namespace std;

const int N = 15;

int n;
int maxx[N];

int main () {
	int T;
	cin >> T;
	while (T--) {
		memset(maxx, 0, sizeof maxx);
		
		cin >> n;
		for (int i = 1;i <= n;++i) {
			int b, d;
			cin >> b >> d;
			maxx[d] = max(maxx[d], b);
		}
		
		int succ = 1;
		int ans = 0;
		for (int i = 1;i <= 10;++i) {
			if (maxx[i] == 0) succ = 0;
			ans += maxx[i];
		}
		if (succ) cout << ans << endl;
		else cout << "MOREPROBLEMS" << endl;
	}
}