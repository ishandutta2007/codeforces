#include<bits/stdc++.h>
#define mid (l+r>>1)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mn = 1 << 20;
string s;
int num[256];
int main() {
	cin >> s;
	int n = s.size(),i,j;
	for (char c : s)num[c]++;
	for (i = 0; i < 256; i++) {
		if (num[i] >= n - 1) {
			printf("Impossible");
			return 0;
		}
	}
	for (i = 0; i < n; i++)s.push_back(s[i]);
	for (i = 0; i < n; i++) {
		bool res = 1;
		for (j = 0; j < n; j++)if (s[i + j] != s[j])res = 0;
		if (res)continue;
		for (j = 0; j < n; j++)if (s[i + j] != s[i + n - 1 - j])res = 1;
		if (res)continue;
		printf("1");
		return 0;
	}
	printf("2");
}