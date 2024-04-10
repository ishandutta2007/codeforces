#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
int res[1000001][2];
map<char, int> ma;
int main() {
	int n,a,b,i,tot=0,to=0;
	string s, t;
	scanf("%d", &n);
	cin >> s >> t;
	a = s.size(), b = t.size();
	ma['R'] = 0, ma['P'] = 1, ma['S'] = 2;
	for (i = 0; i < a; i++)s[i] = ma[s[i]];
	for (i = 0; i < b; i++)t[i] = ma[t[i]];
	for (i = 0; i < a*b; i++) {
		if ((s[i%a] - t[i%b] + 3) % 3 == 1)res[i][0] = 1,to++;
		else if ((s[i%a] - t[i%b] + 3) % 3 == 2)res[i][1] = 1,tot++;
	}
	int q = 0, w = 0;
	q += n / a / b * to, w += n / a / b * tot;
	for (i = 0; i < n % (a*b); i++)q += res[i][0], w += res[i][1];
	printf("%d %d", w,q);
}