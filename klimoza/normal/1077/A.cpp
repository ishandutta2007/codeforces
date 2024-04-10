#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <cmath>
#include <deque>
#include <algorithm>

using namespace std;

typedef long long int ll;


int main() {
	int t;
	cin >> t;
	ll a, b, k;
	for (int i = 0; i < t; i++) {
		cin >> a >> b >> k;
		cout << (a - b) * (k / 2) + (k % 2 == 1 ? a : 0) << "\n";;
	}
	//system("pause");  
	return 0;
}