#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()

const int N = 400005;
char s[N];
vector<string> tmp;

void NO() {
	printf("NO\n");
	exit(0);
}

int main() {
	scanf("%s", s);
	int n = strlen(s);
	int l = 0, r = n - 1;
	int f = 0;
	for (int i = 0; i < n; i++) if (s[i] == '.') f = 1;
	if (!f) NO();
	while (s[l] != '.') l++;
	while (s[r] != '.') r--;
	if (l < 1|| l > 8) NO();
	if (n - 1 - r < 1 || n - 1 - r > 3) NO();
	string a = "";
	for (int i = 0; i < l; i++) a += s[i]; tmp.pb(a);
	int pr = l;
	for (int i = l + 1; i <= r; i++) {
		if (s[i] == '.') {
			if (i - pr - 1 < 2 || i - pr - 1 > 11) NO();
			for (int j = 1; j <= 3; j++) {
				if (i - pr - 1 - j <= 8) {
					a = "";
					for (int k = 0; k < j; k++) a += s[pr + k + 1];
					tmp.pb(a);
					a = "";
					for (int k = j; pr + k + 1 < i; k++) a += s[pr + k + 1];
					tmp.pb(a);
					break;
				}
			}
			pr = i;
		}
	}
	a = ""; for (int i = r + 1; i < n; i++) a += s[i]; tmp.pb(a);
	printf("YES\n");
	for (int i = 0; i < sz(tmp); i += 2)
		cout << tmp[i] << "." << tmp[i + 1]<< endl;
	return 0;
}