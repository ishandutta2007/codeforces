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
	int n;
	cin >> n;
	string s;
	cin >> s;
	bool fl = false;
	for (int i = 0; i < s.size() - 1; i++) {
		if (fl) {
			cout << s[i];
		}
		else {
			if (s[i] > s[i + 1]) {
				fl = true;
				continue;
			}
			else {
				cout << s[i];
			}
		}
	}
	if (fl) {
		cout << s[s.size() - 1];
	}
	//system("pause");  
	return 0;
}