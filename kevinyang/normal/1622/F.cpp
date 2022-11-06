#include <bits/stdc++.h>
using namespace std;
#define int long long
mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count());
vector<int>h(1000005);
vector<int>factor(1000005);
vector<int>f(1000005);
vector<int>ans;
void solve(int n, int val){
	for(int i = 1; i<=n; i++){
		if(f[i]==val){
			ans.push_back(i);
			return;
		}
	}
	map<int,int>hm;
	for(int i = 1; i<=n; i++){
		if(hm[val^f[i]]){
			ans.push_back(i);
			ans.push_back(hm[val^f[i]]);
			return;
		}
		hm[f[i]] = i;
	}
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	if(n==1){
		cout << "1\n1\n";
		return 0;
	}
	for(int i = 2; i<=1000000; i++){
		for(int j = i; j<=1000000; j+=i){
			if(factor[j]==0)factor[j] = i;
		}
	}
	for(int i = 2; i<=1000000; i++){
		if(factor[i]==i){
			h[i] = rng();
		}
		else{
			h[i] = h[factor[i]]^h[i/factor[i]];
		}
	}
	for(int i = 2; i<=1000000; i++){
		f[i] = f[i-1]^h[i];
	}
	if(true){
		int val = 0;
		for(int i = 1; i<=n; i++){
			val^=f[i];
		}
		solve(n,val);
		if(ans.size()){
			set<int>s;
			for(int i = 1; i<=n; i++){
				s.insert(i);
			}
			for(int nxt: ans){
				s.erase(nxt);
			}
			cout << s.size() << "\n";
			for(int nxt: s){
				cout << nxt << " ";
			}
			cout << "\n";
			return 0;
		}
		else{
			val^=f[n];
			solve(n-1,val);
			n--;
			set<int>s;
			for(int i = 1; i<=n; i++){
				s.insert(i);
			}
			for(int nxt: ans){
				s.erase(nxt);
			}
			cout << s.size() << "\n";
			for(int nxt: s){
				cout << nxt << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}