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
	string t;
	cin >> t;
	PolyHash hsh;
	hsh.init(t.size(),t);
	int ans = 0;
	int c0 = count(s.begin(),s.end(),'0');
	int c1 = count(s.begin(),s.end(),'1');
	for(int i = 1; i<=t.size(); i++){
		int v = i*c0;
		int rem = t.size()-v;
		if(rem<=0)continue;
		if(rem%c1!=0)continue;
		int j = rem/c1;
		pair<int,int>a;
		pair<int,int>b;
		int cur = 1;
		for(char nxt: s){
			if(nxt=='0'){
				a = hsh.subhash(cur,cur+i-1);
				cur+=i;
			}
			else{
				b = hsh.subhash(cur,cur+j-1);
				cur+=j;
			}
		}
		if(a==b)continue;
		bool f = true;
		cur = 1;
		for(char nxt: s){
			if(nxt=='0'){
				if(hsh.subhash(cur,cur+i-1)!=a){
					f = false;
				}
				cur+=i;
			}
			else{
				if(hsh.subhash(cur,cur+j-1)!=b){
					f = false;
				}
				cur+=j;
			}
		}
		ans+=f;
	}
	cout << ans << "\n";
	return 0;
}