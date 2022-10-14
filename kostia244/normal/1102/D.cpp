#include <bits/stdc++.h>
using namespace std;
#define DB(x) cout << #x << " == " << x << "\n";
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pi pair<int, int>
#define ll long long
using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, e, c[3] = { 0, }, t = 0;
string s;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> s;
	for (auto& i : s)
		c[i - '0']++;
	e = n / 3;
	if (c[0] < e)
		for (auto& i : s) {
			if (i != '0' && c[i - '0'] > e) {
				c[i - '0']--;
				c[0]++;
				i = '0';
			}
			if (c[0] == e)
				break;
		}
	if (c[1] < e) {
		t = 0;
		for (auto& i : s) {
			if (c[1] >= e)
				break;
			if (i == '0')
				t++;
			if ((i == '2' && c[2] > e)|| (i == '0' && t > e))
				c[1]++, c[i - '0']--, i = '1';
		}
	}
	if (c[2] < e) {
		reverse(s.begin(), s.end());
		for (auto& i : s) {
			if (c[2] >= e)
				break;
			if(i != '2' && c[i-'0'] > e) {
				c[i-'0']--, c[2]++, i = '2';
			}
		}
		reverse(s.begin(), s.end());
	}

	cout << s;
}