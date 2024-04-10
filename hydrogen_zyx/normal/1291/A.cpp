#include<iostream>
#include<cstring>
using namespace std;
char a[3005];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cin >> a;
		bool can = 1;
		int j = n;
		while (j > 1 && ((a[j - 1] - '0') & 1) == 0) j--;
		if (j == 1) can = 0;
		if (!can) {
			cout << -1 << endl;
			continue;
		}
		a[j] = '\0';
		int sum = 0;
		for (int i = 0; i < strlen(a); i++) {
			sum += a[i] - '0';
		}
		int num = -1;
		if (sum & 1) {
			for (int i = 0; i < strlen(a) - 1; i++) {
				if ((a[i] - '0') & 1) {
					num = i;
					break;
				}
			}
			if (num == -1) {
				cout << -1 << endl;
				continue;
			}
			else {
				a[num] = '\0';
				while (a[num + 1] == '0') num++;
				cout << a << a + num + 1 << endl;
			}
		}
		else {
			cout << a << endl;
		}
	}
}