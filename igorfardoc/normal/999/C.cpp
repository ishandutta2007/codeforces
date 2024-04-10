#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vi am(26);
	for(int i = 0; i < n; i++) {
		++am[s[i] - 'a'];
	}
	char now = 'a';
	for(; now <= 'z'; now++) {
		if(am[now - 'a'] > k) break;
		k -= am[now - 'a'];
	}
	int curr = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] < now) continue;
		if(s[i] > now) {
			cout << s[i];
			continue;
		}
		if(curr >= k) cout << s[i];
		++curr;
	}
}