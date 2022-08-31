#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...)
#define endl '\n' // remove in interactive
#endif

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		vector<int> a(m);
		for(int& x: a){
			cin >> x;
			x--;
		}
		// trace(a);
		sort(all(a));
		vector<int> L;
		for(int i = 1; i < m; i++) L.push_back(a[i] - a[i - 1] - 1);
		L.push_back(a[0] + n - 1 - a[m - 1]);
		sort(all(L));
		reverse(all(L));
		// trace(L);
		int t = 0, saved = 0;
		for(int _l: L){
			int l = _l - 2 * t;
			// trace(l);
			if(l <= 0) break;
			if(l <= 2){
				saved++;
				break;
			}
			saved += l - 1;
			t += 2;
		}
		cout << n - saved << endl;
	}
}