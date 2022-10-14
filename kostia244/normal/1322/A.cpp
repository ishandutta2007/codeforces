#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 2e5 + 33, mod = 1e9 + 7;
int n;
string s;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	int mis = 0, p = 0, ans = 0;
	for(auto i : s) {
		if(i=='(')  {
			if(mis) mis--, ans += 2;
			else p++;
		} else {
			if(p) p--;
			else mis++;
		}
	}
	if(mis||p) return cout << -1, 0;
	cout << ans;
}