#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>

using namespace std;

int main() {
	set<int> a;
	int n;
	cin >> n;
	int t;
	for (int i = 0; i < n; i++) {
		cin >> t;
		if(t != 0)	a.insert(t);
	}
	cout << a.size() << "\n";
	//system("pause");
	return 0;
}