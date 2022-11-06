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
	int q;
	cin >> q;
	while(q--){
		int n,k;
		cin >> n >> k;
		string s;
		cin >> s;
		vector<int>arr(n+1);
		for(int i = 1; i<=n; i++){
			if(s[i-1]=='0')arr[i] = 1;
		}
		set<pair<int,int>>s2;
		PolyHash hsh;
		hsh.init(n,arr);
		for(int i = k; i<=n; i++){
			s2.insert(hsh.subhash(i-k+1,i));
		}
		int len = min(20LL,k);
		bool f = false;
		for(int i = 0; i<(1<<len); i++){
			int hshval = 0; int hshval2 = 0;
			for(int j = 0; j<len; j++){
				if(i&(1<<j)){
					hshval+=hsh.powers[j];
					hshval%=hsh.mod;
					hshval2+=hsh.powers2[j];
					hshval2%=hsh.mod2;
				}
			}
			if(s2.find({hshval,hshval2})==s2.end()){
				cout << "YES\n";
				f = true;
				vector<int>ans(k);
				for(int j = 0; j<len; j++){
					if(i&(1<<j)){
						ans[j] = 1;
					}
				}
				reverse(ans.begin(),ans.end());
				for(int j = 0; j<k; j++){
					cout << ans[j];
				}
				cout << "\n";
				break;
			}
		}
		if(!f)cout << "NO\n";
	}	
	return 0;
}