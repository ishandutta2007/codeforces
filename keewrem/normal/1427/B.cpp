#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

void solve(){
	int N,K; cin >> N >> K;
	string q; cin >> q;
	vi v; int cn = 0, c = 0, ans = 0;
	for(auto x: q){
		if (x == 'L'){cn++; c++;}
		else{
			if(c || ans == 0){
				if (c != cn || ans > 0)v.push_back(c);
				c = 0; ans++;
			}else{
				ans+=2;
			}
		}
	}
	if(ans == 0 && K)ans--;
	ans += 2*min(K,cn);
	sort(v.begin(),v.end());
	int s = 0;
	for(auto x: v){
		s+=x; if(s <= K)ans++;
	}
	cout << ans << "\n";
}


int main(){
	int T; cin >> T;
	while(T--)solve();
	return 0;
}