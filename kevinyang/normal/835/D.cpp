#include <bits/stdc++.h>
using namespace std;
#define int long long
struct PolyHash{
	/*
	WARNING: make sure the values in the array or string are in the range [0,5e8]
	*/
	vector<int>powers;
	vector<int>powers2;
	vector<int>hashes;
	vector<int>hashes2;
	int seed = 500002961;
	int seed2 = 500003263;
	const int mod = (int)1e9+7;
	const int mod2 = 998244353;
	vector<int>arr;
	void init(int n){
		powers.resize(n+5); powers[0] = 1;
		powers2.resize(n+5); powers2[0] = 1;
		hashes.resize(n+5);
		hashes2.resize(n+5);
		for(int i = 1; i<=n; i++){
			powers[i] = powers[i-1]*seed; powers[i]%=mod;
			powers2[i] = powers2[i-1]*seed2; powers2[i]%=mod2;
		}
		for(int i = 1; i<=n; i++){
			hashes[i] = hashes[i-1]*seed+arr[i]; hashes[i]%=mod;
			hashes2[i] = hashes2[i-1]*seed2+arr[i]; hashes2[i]%=mod2;
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
	pair<int,int> subhash(int l, int r){//inclusive
		int hsh = hashes[r]-hashes[l-1]*powers[r-l+1]%mod; hsh+=mod; hsh%=mod;
		int hsh2 = hashes2[r]-hashes2[l-1]*powers2[r-l+1]%mod2; hsh2+=mod2; hsh2%=mod2;
		return {hsh,hsh2};
	}
};
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	cin >> s;
	int n = s.length(); PolyHash hsh;
	hsh.init(n,s);
	string s2 = s;
	reverse(s2.begin(),s2.end());
	PolyHash hsh2;
	hsh2.init(n,s2);
	vector<vector<signed>>dp(n+1,vector<signed>(n+1));
	for(int d = 1; d<=n; d++){
		for(int i = 1; d+i-1<=n; i++){
			if(d==1){
				dp[i][i] = 2;
				continue;
			}
			else{
				int m = d/2;
				int j = i+m-1;
				int l = i+d-m;
				int r = i+d-1;
				if(hsh.subhash(i,j)==hsh.subhash(l,r)){
					dp[i][r] = 2*(dp[i][j]|dp[l][r]);
				}
			}
			if(hsh.subhash(i,i+d-1)==hsh2.subhash(n-(i+d-1)+1,n-i+1)){
				dp[i][i+d-1]|=2;
			}
		}
	}
	vector<int>freq(n+5);
	for(int i = 1; i<=n; i++){
		for(int j = i; j<=n; j++){
			for(int k = 1; k<=20; k++){
				if(dp[i][j]&(1<<k)){
					freq[k]++;
				}
			}
		}
	}
	for(int i = 1; i<=n; i++){
		cout << freq[i] << " ";
	}
	cout << "\n";
	return 0;
}