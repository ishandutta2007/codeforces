#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int main() {
	char s[5];
	scanf("%s", s);
	int cnt = 0;
	if (s[0] == 'a' || s[0] == 'h') ++ cnt;
	if (s[1] == '1' || s[1] == '8') ++ cnt;
	if (cnt == 0) printf("8\n");
	else if (cnt == 1) printf("5\n");
	else printf("3\n");
	return 0;
}