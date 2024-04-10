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
	int n, I;
	cin >> n >> I, I *= 8;
	int k = I / n, K = 1;
	for(int i = 1; i <= k && K <= n; i ++){
		K <<= 1;
	}
	vi a(n);
	for(auto &x: a){
		cin >> x;
	}
	sort(a.begin(), a.end());
	vector<pii> b;
	for(int i = 0; i < n; i ++){
		if(b.empty() || a[i] != a[i - 1]){
			b.push_back({a[i], 1});
		}
		else{
			b.back().second ++;
		}
	}
	int res = 1e9;
	vi sum{0};
	for(int i = 0; i < b.size(); i ++){
		sum.push_back(sum.back() + b[i].second);
	}
	for(int i = 0; i < b.size(); i ++){ // i ~ min(n, i + K) - 1
		res = min(res, n - sum[min((int)b.size(), i + K)] + sum[i]);
	}
	cout << res;
	return 0;
}