#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
const ll mod = 1000000007ll;

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int q, t, pos[400400], l = 200009, r = 200010;
	char c;
	cin >> q;
	while(q--) {
		cin >> c >> t;
		if(c == 'L') {
			pos[t] = l--;
		} else if(c == 'R') {
			pos[t] = r++;
		} else {
			cout << min(pos[t]-l-1, r-pos[t]-1) << "\n";
		}
	}
}