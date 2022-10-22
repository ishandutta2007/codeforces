#include <bits/stdc++.h>
using namespace std;
int arr[26][26];
int main() {
	int n, i, j;
	string s;
	cin >> n >> s;
	for (i = 0; i < n - 1; i++) {
		arr[s[i] - 'A'][s[i + 1] - 'A']++;
	}
	int op = 0;
	char a, b;
	for (i = 0; i < 26; i++) {
		for (j = 0; j < 26; j++) {
			if (arr[i][j] > op) {
				op = arr[i][j]; a = i + 'A'; b = j + 'A';
			}
		}
	}
	printf("%c%c", a, b);
}