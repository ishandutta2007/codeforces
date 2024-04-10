#include <bits/stdc++.h>
using namespace std;

int n, o[256], x[256], nx;
char s[200005];

int main()
{
	scanf("%s", s); n = strlen(s);
	for (int i = 0;i < n;i++) o[s[i]]++;
	for (int i = 'a';i <= 'z';i++) if (o[i]&1) x[nx++] = i;
	for (int i = 0, m = (nx>>1);i < m;i++) o[x[i]]++, o[x[nx-i-1]]--;
	for (int i = 'a';i <= 'z';i++) for (int j = 2;j <= o[i];j+=2) printf("%c", (char)i);
	if (n&1) printf("%c", (char)x[nx>>1]);
	for (int i = 'z';i >= 'a';i--) for (int j = 2;j <= o[i];j+=2) printf("%c", (char)i);
	printf("\n"); return 0;
}