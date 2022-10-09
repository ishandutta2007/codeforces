#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	vector<int> s;

	int n, i;
	i=1;
	cin >> n;

	while (1) {
		if (n >= 2*i+1) {
			s.push_back(i);
			n -= i;
			i++;
		} else {
			s.push_back(n);
			break;
		}
	}

	cout << s.size() << '\n';
	for (int x : s) {
		cout << x << ' ';
	}

	

}