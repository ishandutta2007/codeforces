#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N = 1000050;
char s[N];
bool used[N];
int len;
int dfs(int x) {
	if (used[x]) return 0;
	used[x] = true;
	int ans = 1;
	ans += dfs((x-1+len-1)%len+1);
	ans += dfs(x%len+1);
	return ans;
}
int main() {
	scanf ("%s", s + 1);
	len = strlen(s+1);
	int ans = 0;
	for (int i = 1;i <= len; i++) {
		if (s[i] != s[(i-1+len-1)%len+1]) {
			if (s[i%len+1] == s[i]) {
				ans++;
				int k = s[i];
				for (int j = i;; j++) {
					if (j == len + 1) j -= len;
					used[j] = true;
					if (s[j] != k || used[j%len+1]) break;
				}
			}
		}
	}
//	for (int i = 1;i <= len; i++) cout << used[i] << endl;
	for (int i = 1;i <= len; i++)
		if (!used[i]) ans += (dfs(i) + 1) / 2;
	cout << ans << endl;
	return 0;
}