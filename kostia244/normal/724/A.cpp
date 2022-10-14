#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
const ll mod = 998244353ll;
int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
map<string, int> a = {{"monday", 1}, {"tuesday", 2}, {"wednesday", 3}, {"thursday", 4}, {"friday", 5}, {"saturday", 6}, {"sunday", 0}};
int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	string s, t;
	int x, b;
	cin >> s >> t;
	x = a[s];
	b = a[t];
	for(int i = 0; i < 12; i++) {
		if((x+months[i])%7 == b) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO";
}