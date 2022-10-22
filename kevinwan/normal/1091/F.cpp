#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const ll mod = 998244353;
const int mn = 100005;
ll d[mn],l[mn],lim[mn],idk[mn];
string s;
ll ans,def,dis,fly;
int main() {
	int n,i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)scanf("%lld", d + i);
	cin >> s;
	s.push_back(' ');
	l[0] = d[0];
	for (i = 1; i < n; i++) {
		if (s[i] == 'L')l[i] = l[i - 1] - d[i];
		else l[i] = l[i - 1] + d[i];
	}
	lim[n - 1] = l[n - 1];
	for (i = n - 2; i >= 0; i--)lim[i] = min(l[i], lim[i + 1]);
	memset(idk, 0x3f, sizeof(idk));
	if (s[n - 1] == 'L')idk[n - 1] = l[n-1];
	for (i = n - 2; i >= 0; i--) {
		if (s[i] == 'L')idk[i] = min(idk[i+1],l[i]);
		else idk[i] = 0x3f3f3f3f3f3f3f3f;
	}
	for (i = 0; i < n; i++) {
		if (s[i] == 'W') {
			if (lim[i] - def < 0) {
				ans += 3 * (def - lim[i]);
				dis += def - lim[i];
				def = lim[i];
			}
			ans += d[i] * 3;
		}
		else if (s[i] == 'G') {
			if (lim[i] - def > 0) {
				ll go = min(2*d[i], lim[i] - def);
				fly += go;
				ans -= 2 * go;
				def +=go;
			}
			else if (idk[i+1] - def < 0 && s[i + 1] == 'L') {
				ans += 5 * (def - idk[i+1]);
				dis += def - idk[i+1];
				def = idk[i+1];
			}
			ans += d[i] * 5;
		}
		else {
			ans += d[i];
			fly += 2*d[i];
		}
		dis += d[i];
	}
	ans -= dis - fly;
	printf("%lld", ans);
}