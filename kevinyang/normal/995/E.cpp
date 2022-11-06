#include <bits/stdc++.h>
using namespace std;
#define int long long
mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count());
int mod = (int)1e9+7;
int modpow(int x, int y) {
	return !y?1:((y % 2 ? x : 1) * modpow((x * x) % mod, y / 2)) % mod;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int u,v,p;
	cin >> u >> v >> p;
	mod = p;
	map<int,vector<int>>hm;
	unordered_set<int>s;
	int reps = 1e5;
	for(int t = 0; t<reps; t++){
		vector<int>a;
		int cur = u;
		for(int i = 0; i<100; i++){
			int val = rng()%3;
			if(val==0){
				cur++; cur%=mod;
			}
			if(val==1){
				cur+=mod-1; cur%=mod;
			}
			if(val==2){
				cur = modpow(cur,mod-2);
			}
			a.push_back(val);
		}
		hm[cur] = a;
		s.insert(cur);
	}
	for(int t = 0; t<reps; t++){
		vector<int>a;
		int cur = v;
		for(int i = 0; i<100; i++){
			int val = rng()%3;
			if(val==0){
				cur--; cur%=mod;
			}
			if(val==1){
				cur++;
				cur%=mod;
			}
			if(val==2){
				cur = modpow(cur,mod-2);
			}
			a.push_back(val);
		}
		if(s.count(cur)){
			cout << "200\n";
			for(int nxt: hm[cur]){
				cout << nxt+1 << " ";
			}
			reverse(a.begin(),a.end());
			for(int nxt: a){
				cout << nxt+1 << " ";
			}
			cout << "\n";
			return 0;
		}
	}
	return 0;
}