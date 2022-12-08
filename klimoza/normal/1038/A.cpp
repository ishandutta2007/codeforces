#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(26);
	string s;
	cin >> s;
	for (char i : s) {
		a[(int)i - 65]++;
	}
	int mini = a[0];
	for (int i = 1; i < k; i++) {
		mini = min(mini, a[i]);
	}
	cout << mini * k << "\n";
	//system("pause");
	return 0;
}