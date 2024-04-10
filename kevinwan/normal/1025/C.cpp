#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	string s;
	int n,i;
	cin >> s;
	n = s.size();
	int l = 1,ans=0;
	char c = s[0];
	for (i = 1; i < 2*n; i++) {
		if (s[i%n]!=c)l++;
		else ans=max(ans,l),l = 1;
		c = s[i%n];
	}
	ans = max(ans, l);
	printf("%d", min(ans, n));
	getchar(); getchar();
}