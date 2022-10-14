#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
const ll mod = 998244353ll;
int m;
string s;

int check(char x) {
	int lst = -1, cov = m-2, ans = 0;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] < x) {
			cov = i+m-1;
		}
		if(s[i] == x) {
			lst = i;
		}
		if(i > cov) {
			ans++;
			cov = lst+m-1;
		}
		if(i > cov)
			return -1;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> m >> s;
	for(char c = 'a'; c <= 'z'; c++) {
		int t= check(c);
		if(t != -1) {
			sort(all(s));
			for(auto i : s)
				if(i < c) cout << i;
			while(t--) cout << c;
			return 0;
		}
	}
}