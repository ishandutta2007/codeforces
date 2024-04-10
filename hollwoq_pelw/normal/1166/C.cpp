#include <bits/stdc++.h>
using namespace std;

int n; vector<int> a;
 
void Input() {
	cin >> n; a.resize(n);
	for (auto &z: a) {cin >> z; z = abs(z);}
}
 
void Solve() {
	long long ans = 0;
	sort(a.begin(), a.end());
	for (int i=0; i<n; i++) {
		int j = upper_bound(a.begin(), a.end(), a[i] * 2) - a.begin();
		ans += max(0, j - i - 1);
	}
	cout << ans << endl;
}
 
int main(int argc, char* argv[]) {
	Input(); 
	Solve(); 
	return 0;
}