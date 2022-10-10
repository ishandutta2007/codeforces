#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t --){
		int n;
		cin >> n;
		vector<int> a(n);
		for(auto &x: a){
			cin >> x;
		}
		if(n < 3){
			cout << 0 << "\n";
			continue;
		}
		sort(a.begin(), a.end());
		cout << min(n - 2, a[n - 2] - 1) << "\n";
	}
	return 0;
}