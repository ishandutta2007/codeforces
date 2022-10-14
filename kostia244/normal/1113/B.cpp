#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define DB(x) cout << #x << " == " << x << "\n";
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define vi vector<int>
#define pi pair<int, int>
using namespace std;//1 + 1 + 2 + 3 + 4 + 5 + 6 + 8
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, m = 1000000000, cs, s = 0, ts, ans = 0;
vi v;

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> n;
	v.resize(n);
	for(auto& i : v)
		cin >> i, s += i, m = min(m, i);
	cs = s;
	for(auto& i : v) {
		for(int d = 1; d * d <= i; d++) {
			if(i%d)
				continue;
			ts = cs - m;
			ts -= i;
			ts += m * d;
			ts += i/d;
			if(ts < s)
				s = ts;
			ts = cs - m;
			ts -= i;
			ts += m * (i/d);
			ts += i/(i/d);
			if(ts < s)
				s = ts;
		}
	}
	cout << s;
}