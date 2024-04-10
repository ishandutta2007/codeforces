#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int a, b, c, s;
	cin >> a >> b >> c;
	s = a+b+c;
	s = min(s, a+a+b+b);
	s = min(s, a+a+c+c);
	s = min(s, b+b+c+c);

	cout << s;
}