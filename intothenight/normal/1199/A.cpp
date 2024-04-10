#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x, y;
	cin >> n >> x >> y;
	vi a(n);
	for(auto &x: a){
		cin >> x;
	}
	for(int i = 0; i < n; i ++){
		if(all_of(a.begin() + max(0, i - x), a.begin() + min(n, i + y + 1), [&](int A){return A >= a[i];})){
			cout << i + 1;
			return 0;
		}
	}
	return 0;
}