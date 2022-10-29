#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
struct zi {
	char c;
	int s;
};
zi a[300];
int se[300];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char ch;
		cin >> ch;
		if (i == 0) {
			a[0] = { ch,0 };
			se[0] = 0;
			continue;
		}
		if (ch >= a[i - 1].c) {
			a[i].c = ch;
			a[i].s = a[i - 1].s;
			se[i] = a[i].s;
		}
		else {
			int j = i - 1, color = 1 - a[i - 1].s;
			while (a[j].c > ch) {
				if (a[j].s == color) { cout << "NO"; return 0; }
				a[j + 1] = a[j];
				j--;
			}
			a[j + 1] = { ch,color };
			se[i] = color;
		}
	}
	cout << "YES" << endl;
	for (int i = 0; i < n; i++) {
		cout << se[i];
	}
}