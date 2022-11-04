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
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> a(m);
	for(int i = 0; i < m; i++) {
		string s = "";
		for(int j = 0; j < m; j++) {
			s += '0';
		}
		s[i] = '1';
		cout << "? " << s << endl;
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin(), a.end());
	string s = "";
	for(int i = 0; i < m; i++) {
		s += '0';
	}
	int now = 0;
	for(int i = 0; i < m; i++) {
		s[a[i].second] = '1';
		cout << "? " << s << endl;
		int curr;
		cin >> curr;
		if(curr == now + a[i].first) {
			now = curr;
			continue;
		}
		s[a[i].second] = '0';
	}
	cout << "! " << now << endl;

}