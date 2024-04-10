#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007LL
set<int> of;
ll cont;
int lo = -1, hi = 0x3f3f3f3f;
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n,x,i;
	string s;
	cin >> n;
	of.insert(-1);
	of.insert(0x3f3f3f3f);
	for (i = 0; i < n; i++) {
		cin >> s>>x;
		if (s[1] == 'D') {
			of.insert(x); continue;
		}
		if (x<lo || x>hi) { cout << 0; getchar(); getchar(); return 0; }
		if (x > lo&&x < hi)cont++;
		set<int>::iterator it=of.find(x);
		it++;
		hi=*it;
		it--, it--;
		lo = *it;
		it++;
		of.erase(it);
	}
	ll ans = 1;
	for (i = 0; i < cont; i++)ans *= 2, ans %= mod;
	ll num=1;
	for (int x : of)if (x > lo&&x < hi)num++;
	ans *= num, ans %= mod;
	printf("%lld", ans);
	getchar(); getchar();
}