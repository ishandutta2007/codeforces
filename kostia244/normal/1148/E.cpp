#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
const ll mod = 1000000007ll;
int n;
vector<pair<int, int>> a;
vi b;
int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> n;
	for(int t, i = 0; i < n; i++) {
		cin >> t;
		a.pb({t, i+1});
	}
	sort(all(a));
	b.resize(n);
	for(auto& i : b)
		cin >> i;
	sort(all(b));
	ll d = 0;
	for(int i = 0; i < n; i++) {
		d += b[i]-a[i].first;
		a[i].first = a[i].first-b[i];
		if(d < 0) {
			cout << "NO";
			return 0;
		}
	}
	if(d) {
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	stack<int> st;
	vector<vi> ans;
	for(int i = 0; i < n; i++) {
//		cout << a[i].first << " ";
		if(a[i].first < 0) {
			st.push(i);
//			cout << "++\n";
		}
		if(a[i].first <= 0) continue;
		int &t = a[i].first;
//		cout << t << " ";
		while(t&&st.size()) {
			int j = st.top();
			int k = min(t, (int)-a[j].first);
			t-=k;
			a[j].first+=k;
			ans.pb({a[j].second,a[i].second,k});
			if(!a[j].first)st.pop();
		}
//		cout << t << " " << st.size() << "\n";
	}
	cout << ans.size() << "\n";
	for(auto i : ans)
		cout << i[0] << " " << i[1] << " " << i[2] << "\n";
}