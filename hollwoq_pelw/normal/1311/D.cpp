#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
	cin >> q;
	while (q--) {
		int a,b,c;
		cin >> a >> b >> c;
		int N = (int)2e4;
		int ans = (int)1e9;
		vector<int> res;
		for (int i = 1;i <= N;++i) {
			for (int j = i;j <= N;j += i) {
				for (int k = j;k <= N;k += j) {
					int tong = abs(i - a) + abs(j - b) + abs(k - c);
					if (tong < ans) {
						ans = tong;
						res = {i,j,k};
					}
				}
			}
		}
		cout << ans << "\n";
		for (auto&x : res) cout << x <<" ";cout <<"\n";
	}
}