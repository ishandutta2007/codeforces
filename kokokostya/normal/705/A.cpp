#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <queue>

using namespace std;

int main() {
	string s = "I hate ";
	string t = "I love ";
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		if (i)
			cout << "that ";
		if (i % 2 == 0)
			cout << s;
		else
			cout << t;
	}
	cout << "it";
	
	return 0;
}