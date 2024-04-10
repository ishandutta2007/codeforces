#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
void idk(int a, int b, int c) {
	string t;
	int i,l=b-a+1;
	for (i = 0; i < l; i++)t.push_back(s[a + (i - c + l * 10000000LL) % l]);
	for (i = 0; i < l; i++)s[a + i] = t[i];
}
int main() {
	cin >> s;
	int q,a,b,c;
	scanf("%d", &q);
	while (q--) {
		scanf("%d%d%d", &a, &b, &c);
		idk(a - 1, b - 1, c);
	}
	cout << s;
	getchar(); getchar();
}