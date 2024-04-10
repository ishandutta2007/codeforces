#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
char s[200010], t[200010];
int a[26][100010];
int pp[26];
int fen(int* v, int n, int k);
int main() {
	std::ios::sync_with_stdio(false);
	int tt;
	cin >> tt;
	while (tt--) {
		for (int i = 0; i < 26; i++) pp[i] = 0;
		cin >> s >> t;
		for (int i = 0; i < strlen(s); i++) {
			a[s[i] - 'a'][pp[s[i] - 'a']++] = i;
		}
		/*for (int i = 0; i < 26; i++) {
			for (int j = 0; j < pp[i]; j++) {
				cout << a[i][j] << ' ';
			}
			cout << endl;
		}*/
		int cnt = 0, p = 0;
		for (int i = 0; i < strlen(t); i++) {
			if (pp[t[i] - 'a'] == 0) {
				cnt = -1;
				break;
			}
			int ppp;
			ppp = fen(a[t[i] - 'a'], pp[t[i] - 'a'], p);
			if (ppp == pp[t[i] - 'a']) {
				p = 0;
				i--;
				cnt++;
				continue;
			}
			else p = a[t[i] - 'a'][ppp] + 1;
		}
		if (cnt != -1) cnt++;
		cout << cnt << endl;
	}
}
int fen(int* v, int n, int k) {
	//cout << n << ' ' << k << endl;
	int l = 0, r = n;
	while (l < r) {
		int mid = l + (r - l) / 2;
		if (v[mid] >= k) r = mid;
		else l = mid + 1;
	}
	//cout << l << endl;
	return l;
}