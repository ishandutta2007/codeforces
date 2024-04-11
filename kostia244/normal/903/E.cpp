#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
const ll mod = 998244353ll;
int k, n;
vector<string> a;
bool cc;
bool check(string& s) {
	int c;
	for(auto &i : a) {
		c = 0;
		for(int j = 0; j < n; j++)
			c += s[j] != i[j];
		if(c&&c!=2)
			return false;
		if(cc==false&&c==0)
			return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> k >> n;
	a.resize(k);
	for(auto &i : a) cin >> i;
	int j = 0;
	for(int i = 1; i < k; i++) {
		if(a[i] != a[0]) {
			j = i;
			int c = 0;
			for(int k = 0; k < n; k++)
				if(a[i][k] != a[0][k]) c++;
			if(c == 4) {
			break;
			}
		}
	}
	if(j == 0) {
		swap(a.back()[0], a.back()[1]);
		cout << a.back();
		return 0;
	}
	string x = a[0], y = a[j];
//	cout << x << " " << y << " ";
	vi mis, o;
	vector<char> xx, yy;
	for(int i = 0; i < n; i++)
		if(x[i] != y[i]) {
			mis.pb(i);
			xx.pb(x[i]);
			yy.pb(y[i]);
		}
	sort(all(xx));
	sort(all(yy));
	if(mis.size() > 4 || xx != yy) {
		cout << -1;
		return 0;
	}
	o = mis;
	set<char> st(all(a.back()));
	cc = st.size()!=a.back().size();
	do {
		string s = x;
		for(int i = 0; i < mis.size(); i++)
			s[o[i]] = x[mis[i]];
		if(check(s)) {
			cout << s;
			return 0;
		}
	} while(next_permutation(all(mis)));
	cout << -1;
}