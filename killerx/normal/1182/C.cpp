#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector <int>
#define pii pair <int, int>
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,n) for (int i = 0; i < (int) (n); ++ i)
#define foreach(it,c) for (__typeof(c.begin()) it = c.begin(); it != c.end(); ++ it)

inline int read() {
	int x = 0, f = 1, c = getchar();
	for (;!isdigit(c);c = getchar()) if (c == '-') f ^= 1;
	for (; isdigit(c);c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}

const char * vowel = "aeiou";
map <int, vi> word[5];
int ans[100005][4];
string s[100005];
vi len[1000005];
int main() {
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	rep(i, n) {
		cin >> s[i];
		int lst = -1, cnt = 0;
		rep(j, s[i].size()) {
			int id = -1;
			rep(k, 5) if (vowel[k] == s[i][j]) id = k;
			if (~id) {
				++ cnt;
				lst = id;
			}
		}
		word[lst][cnt].pb(i);
	}
	int cnt = 0;
	rep(i, 5) foreach(it, word[i]) {
		for (int j = 0; j + 1 < it -> second.size(); j += 2) {
			ans[cnt][1] = it -> second[j];
			ans[cnt][3] = it -> second[j + 1];
			cnt ++;
		}
		if (it -> second.size() & 1) {
			len[it -> first].pb(it -> second.back());
		}
	}
	int cntt = 0;
	rep(i, 1000001) {
		for (int j = 0; j + 1 < len[i].size(); j += 2) {
			ans[cntt][0] = len[i][j];
			ans[cntt][2] = len[i][j + 1];
			cntt ++;
		}
	}
	while (cnt > cntt) {
		ans[cntt][0] = ans[cnt - 1][1];
		ans[cntt][2] = ans[cnt - 1][3];
		cntt ++; -- cnt;
	}
	int anss = min(cnt, cntt);
	cout << anss << endl;
	rep(i, anss) {
		cout << s[ans[i][0]] << " " << s[ans[i][1]] << endl;
		cout << s[ans[i][2]] << " " << s[ans[i][3]] << endl;
	}
	return 0;
}