#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int n;
char s[105];

int main() {
	scanf("%d", &n);
	scanf("%s", s);
	int cnt = 0;
	rep(i, n) if (s[i] == '0') ++ cnt;
	if (cnt == n) puts(s);
	else {
		printf("1");
		rep(i, cnt) printf("0");
		puts("");
	}
	return 0;
}