#include <vector>
#include <string>
#include <iostream>
using namespace std;


int main(void) {
	int n, k;
	cin.sync_with_stdio(false);
	cin >> n >> k;
	string str;
	cin >> str;
	/*if (k == 1) {
		for (int i = 0; i < n; ++i)
			cout << "1";
		cout << endl;
		return 0;
	}*/
	vector<int> pi(n);
	for (int i = 1; i<n; ++i) {
		int j = pi[i - 1];
		while (j > 0 && str[i] != str[j])
			j = pi[j - 1];
		if (str[i] == str[j])  ++j;
		pi[i] = j;
	}
	if (k == 1)
		cout << '1';
	else
		cout << '0';
	int j = 0;
	for (int i = 1; i<n; ++i) {
		while (j > 0 && str[i] != str[j])
			j = pi[j - 1];
		if (str[i] == str[j])  ++j;
		int saved = j;
		while (i / ((i + 1) - j) > k) {
			saved = j;
			j = pi[j - 1];
		}
		if ((i + 1) / (i + 1 - j) == k || i / (i + 1 - j) == k) {
			cout << "1";
		}
		else {
			j = saved;
			cout << "0";
		}
	}
	cout << endl;
}