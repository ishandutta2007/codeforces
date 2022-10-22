#include <iostream>
#include <set>

using namespace std;

int main() {
	set<int> s;
	for (int i = 0; i < 4; i++) {
		int tmp;
		cin >> tmp;
		s.insert(tmp);
	}
	cout << 4-s.size() << endl;
	return 0;
}