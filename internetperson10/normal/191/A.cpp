#include <bits/stdc++.h>

using namespace std;

int arr[26][26];
int arr2[26][26];

int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int x = s.at(0) - 'a';
		int y = s.at(s.size()-1) - 'a';
		for(int j = 0; j < 26; j++) {
			if(arr[j][x] > 0) arr2[j][y] = max(arr[j][y], arr[j][x] + (int)s.size());
		}
		arr2[x][y] = max(arr2[x][y], (int)s.size());
		for(int j = 0; j < 26; j++) {
			for(int k = 0; k < 26; k++) {
				arr[j][k] = max(arr[j][k], arr2[j][k]);
				arr2[j][k] = 0;
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < 26; i++) {
		ans = max(ans, arr[i][i]);
	}
	cout << ans << '\n';
}