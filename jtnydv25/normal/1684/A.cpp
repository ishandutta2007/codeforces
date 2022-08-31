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
		int n; cin >> n;
		vector<int> v;
		int l = 0;
		while(n){
			v.push_back(n % 10);
			n /= 10;
			l++;
		}
		if(l == 2){
			cout << v[0] << endl;
			continue;
		}
		sort(all(v));
		cout << v[0] << endl;
		
	}
}