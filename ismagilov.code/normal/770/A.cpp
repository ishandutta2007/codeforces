#include <iostream>
#include <cmath>
#include <set>
#include <algorithm>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <bitset>

using namespace std;



int main() {	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cerr.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cout << char('a' + i % k);
	}
	
}