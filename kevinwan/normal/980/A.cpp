#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	int a=0, b=0;
	for (char c : s) {
		if (c == '-')a++;
		if(c=='o') b++;
	}
	if (b == 0) {
		printf("YES");
		return 0;
	}
	if (a%b == 0)printf("YES");
	else printf("NO");
}