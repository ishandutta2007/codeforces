#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...) // remove in interactive
#define endl '\n'
#endif

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<ll> a(n);
		int s = 0;
		for(ll& x: a){
			cin >> x;
			while(x % 2 == 0){
				x /= 2;
				s++;
			}
		}
		auto it = max_element(all(a)) - a.begin();
		a[it] <<= s;
		cout << accumulate(all(a), 0LL) << endl;
		
	}
}