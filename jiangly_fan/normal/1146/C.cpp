#include<bits/stdc++.h>
using LL = long long;
using namespace std;
constexpr int maxn = 120000;
void no(){
	cout << "NO";
	exit(0);
}
void solve(int n){
	int ans = 0;
	for(int k = 1; k <= n; k <<= 1){
		set<int> a, b;
		for(int i = 1; i <= n; i += 1) if(i & k) a.insert(i);
		else b.insert(i);
		if(a.size() and b.size()){
			cout << a.size() << " " << b.size() << " ";
			for(int x : a) cout << x << " ";
			for(int x : b) cout << x << " ";
			cout << endl;
			int pans = 0;
			cin >> pans;
			ans = max(pans, ans);
		}
	}
	cout << "-1 " << ans << endl;
}
int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t --){
		int n;
		cin >> n;
		solve(n);
	} 
}