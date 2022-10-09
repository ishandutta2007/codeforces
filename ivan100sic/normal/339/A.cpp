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

	string s;
	cin >> s;
	for (int i=0; i<s.size(); i+=2) {
		for (int j=i+2; j<s.size(); j+=2) {
			if (s[i] > s[j]) {
				swap(s[i], s[j]);
			}
		}
	}
	cout << s;
}