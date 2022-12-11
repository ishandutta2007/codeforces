#include <bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define ucin() ios :: sync_with_stdio(0)
typedef vector<int> vi;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;
typedef double db;

const int N = 1e5 + 10;

int main() {
	ucin();
	int t; cin >> t;
	static char s[N], ans[N];
	while(t --) {
		int n, R, P, S;
		cin >> n >> R >> P >> S >> s + 1;
		int cnt = 0;
		for(int i = 1; i <= n; i ++) ans[i] = -1;
		for(int i = 1; i <= n; i ++) {
			if(s[i] == 'R' && P) P --, cnt ++, ans[i] = 'P';
			if(s[i] == 'P' && S) S --, cnt ++, ans[i] = 'S';
			if(s[i] == 'S' && R) R --, cnt ++, ans[i] = 'R';
		}
		if(cnt >= (n + 1) / 2) {
			cout << "YES\n";
			for(int i = 1; i <= n; i ++) if(ans[i] == -1) {
				if(P) P --, ans[i] = 'P';
				else if(S) S --, ans[i] = 'S';
				else if(R) R --, ans[i] = 'R'; 
			}
			ans[n + 1] = '\0';
			cout << ans + 1 << "\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}