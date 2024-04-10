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
		string s, c("RGB");
		cin >> s;
		int res = 1e9;
		for(int first = 0; first < 3; first ++){
			int cnt = 0;
			auto it = first;
			for(int i = 0; i < k; i ++){
				if(s[i] != c[it]){
					cnt ++;
				}
				it ++;
				if(it == 3){
					it = 0;
				}
			}
			res = min(res, cnt);
			for(int i = k; i < n; i ++){
				if(s[i - k] != c[(it + 2 * k) % 3]){
					cnt --;
				}
				if(s[i] != c[it]){
					cnt ++;
				}
				res = min(res, cnt);
				it ++;
				if(it == 3){
					it = 0;
				}
			}
		}
		cout << res << "\n";
	}
	return 0;
}