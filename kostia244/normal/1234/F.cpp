#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
const ll mod = 998244353ll;
int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int can[1<<20];
	memset(can, 0, sizeof can);
	string s;
	cin >> s;
	int i = 0, j = 0;
	while(i < s.size()) {
		int msk = 0;
		j = i;
		while(j < s.size() && ((msk>>(s[j]-'a'))&1) == 0) {
			msk |= 1<<(s[j++]-'a');
			can[msk]=1;
		}
		i++;
	}
	for(int msk = 0; msk < 1<<20; msk++)
		if(can[msk]) can[msk] = __builtin_popcount(msk);
	for(int i = 0; i < 20; i++)
		for(int msk = 0; msk < 1<<20; msk++)
			if(msk & (1<<i))
				can[msk] = max(can[msk], can[msk ^ (1<<i)]);
	int ans = 0;
	for(int msk = 0; msk < 1<<20; msk++)
		ans = max(ans, can[msk] + can[((1<<20)-1)^msk]);
	cout << ans;
}