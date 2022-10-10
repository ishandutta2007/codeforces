#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> v(n);
	for(auto &x: v){
		cin >> x;
	}
	auto p = max_element(v.begin(), v.end());
	is_sorted(v.begin(), p) && is_sorted(p + 1, v.end(), greater<int>()) ? cout << "YES" : cout << "NO";
	return 0;
}