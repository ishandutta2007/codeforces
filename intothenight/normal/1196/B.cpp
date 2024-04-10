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
	int qq;
	cin >> qq;
	while(qq --){
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for(auto &x: a){
			cin >> x;
		}
		vector<int> res;
		bool s = 0;
		for(int i = 0; i < n; i ++){
			if(res.size() < k && a[i] & 1){
				res.push_back(i + 1);
			}
			if(res.size() == k && a[i] & 1){
				s = !s;
			}
		}
		if(res.size() == k && s){
			cout << "YES\n";
			for(int i = 0; i < res.size() - 1; i ++){
				cout << res[i] << " ";
			}
			cout << n << "\n";
		}
		else{
			cout << "NO\n";
		}
	}
	return 0;
}