
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	string s;
	scanf("%d", &n);
	cin >> s;
	if(s=="0"){
		printf("0");
		return 0;
	}
	printf("1");
	for (int i = 0; i < n; i++)if (s[i] == '0')printf("0");
}