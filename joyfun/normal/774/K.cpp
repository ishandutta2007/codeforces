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

const int N = 100005;
const char a[10] = "aeiouy";
int n;
char s[N];

bool judge(char c) {
	for (int i = 0; i < 6; i++) if (a[i] == c) return true;
	return false;
}

int main() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++) {
		int j = i;
		int f = judge(s[i]);
		while (f && j <= n && s[j] == s[i]) j++;
		printf("%c", s[i]);
		if (j - i >= 3 || (j - i == 2 && s[i] != 'o' && s[i] != 'e')) i = j - 1;
	}
	return 0;
}