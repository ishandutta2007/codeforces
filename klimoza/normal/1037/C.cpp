#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;



int main() {
	int n;
	cin >> n;
	string s1, s2;
	cin >> s1 >> s2;
	vector<bool> used(n);
	int count = 0;
	if (s1[0] == s2[0]) {
		used[0] = true;
	}
	for (int i = 1; i < n; i++) {
		if (s1[i] != s2[i]) {
			if (s2[i] == '0') {
				if (s2[i - 1] == '1' && !used[i - 1]) {
					count++;
					used[i - 1] = true;
					used[i] = true;
				}
				else if (s2[i - 1] == '0' && !used[i - 1]) {
					used[i - 1] = true;
					count++;
				}
			}
			else {
				if (s2[i - 1] == '0' && !used[i - 1]) {
					count++;
					used[i - 1] = true;
					used[i] = true;
				}
				else if (s2[i - 1] == '1' && !used[i - 1]) {
					used[i - 1] = true;
					count++;
				}
			}
		}
		else {
			used[i] = true;
			if (!used[i - 1]) {
				used[i - 1] = true;
				count++;
			}
		}
	}
	if (!used[n - 1]) {
		count++;
	}
	cout << count << "\n";
	//system("pause");
	return 0;
}