#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct PolyHash{
	/*
	WARNING: make sure the values in the array or string are in the range [0,5e8]
	*/
	vector<int>powers;
	vector<int>hashes;
	int seed = 500002961;
	const int mod = (int)1e9+7;
	vector<int>arr;
	void init(int n){
		powers.resize(n+5); powers[0] = 1;
		hashes.resize(n+5);
		for(int i = 1; i<=n; i++){
			powers[i] = ((ll)powers[i-1]*seed);
		}
		for(int i = 1; i<=n; i++){
			hashes[i] = (((ll)hashes[i-1]*seed+arr[i]));
		}
	}
	void init(int n, string s){//string is 0 indexed
		arr.resize(n+5);
		for(int i = 1; i<=n; i++){
			arr[i] = s[i-1];
		}
		init(n);
	}
	void init(int n, vector<int>a){//a is 1 indexed
		arr.resize(n+5);
		for(int i = 1; i<=n; i++){
			arr[i] = a[i];
		}
		init(n);
	}
	int subhash(int l, int r){//inclusive
		int hsh = hashes[r]-hashes[l-1]*powers[r-l+1];
		return hsh;
	}
};

signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	cin >> s;
	string s2 = s;
	int n = s.length();
	reverse(s2.begin(),s2.end());
	PolyHash hsh;
	PolyHash hsh2;
	hsh.init(n,s);
	hsh2.init(n,s2);
	vector<int>dp(n+1);
	int ans = 0;
	for(int i = 1; i<=n; i++){
		if(hsh.subhash(1,i)==hsh2.subhash(n-i+1,n)){
			dp[i] = dp[i/2]+1;
			ans+=dp[i];
		}
	}
	cout << ans << "\n";
	return 0;
}