#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
map<int, int> id;
int getid(int x) {
	if(!id.count(x))
		id[x] = id.size();
	return id[x];
}
int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int n;
	vi cnta(200003, 0), cntb(200003, 0);
	cin >> n;
	int a, b;
	for(int i = 0; i < n; i++) {
		cin >> a >> b;
		cnta[getid(a)]++;
		if(a != b)
		cntb[getid(b)]++;
	}
	int ans = n+100, T = (n+1)/2;
	for(int i = 0; i < 200003; i++) {
		if(cnta[i]+cntb[i] >= T)
			ans = min(ans, max(0, T-(int)cnta[i]));
	}
	if(ans > n)
		ans = -1;
	cout << ans;
}