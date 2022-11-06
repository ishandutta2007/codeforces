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
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		string ss = s;
		ss+="$";
		n++;
		vector<pair<int,int>>arr(n);
		for(int i = 0; i<n; i++){
			arr[i] = make_pair((int)ss[i],i);
		}
		sort(arr.begin(),arr.end());
		vector<int>indices(n);//stores the index of the hashes of string starting at i
		vector<int>hashes(n);
		hashes[0] = 0;
		for(int i = 1; i<n; i++){
			if(arr[i].first==arr[i-1].first)hashes[i] = hashes[i-1];
			else hashes[i] = hashes[i-1]+1;
		}
		for(int i = 0; i<n; i++){
			arr[i] = make_pair(hashes[i],arr[i].second);
		}
		for(int i = 1; i<n; i*=2){
			for(int j = 0; j<n; j++){
				indices[arr[j].second] = j;
			}
			for(int j = 0; j<n; j++){
				int ind1 = j; int ind2 = (j+i)%n;
				int idx1 = indices[ind1]; int idx2 = indices[ind2];//idx is the index of the hash and the actual starting index
				int hash = hashes[idx1]*500000 + hashes[idx2];
				arr[idx1] = make_pair(hash,arr[idx1].second);
			}
			vector<int>count(n);
			vector<int>pos(n);
			vector<pair<int,int>>newarr(n);
			for(int j = 0; j<n; j++){
				int sec = arr[j].first%500000;
				count[sec]++;
			}
			for(int j = 1; j<n; j++){
				pos[j] = pos[j-1]+count[j-1];
			}
			for(int j = 0; j<n; j++){
				int sec = arr[j].first%500000;
				newarr[pos[sec]] = arr[j];
				pos[sec]++;
			}
			for(int j = 0; j<n; j++){
				count[j] = 0; pos[j] = 0;
			}
			for(int j = 0; j<n; j++){
				int fir = newarr[j].first/500000;
				count[fir]++;
			}
			for(int j = 1; j<n; j++){
				pos[j] = pos[j-1]+count[j-1];
			}
			for(int j = 0; j<n; j++){
				int fir = newarr[j].first/500000;
				arr[pos[fir]] = newarr[j];
				pos[fir]++;
			}
			//sort(arr.begin(),arr.end());
			hashes[0] = 0;
			for(int i = 1; i<n; i++){
				if(arr[i].first==arr[i-1].first)hashes[i] = hashes[i-1];
				else hashes[i] = hashes[i-1]+1;
			}
			for(int i = 0; i<n; i++){
				arr[i] = make_pair(hashes[i],arr[i].second);
			}
		}
		for(int j = 0; j<n; j++){
			indices[arr[j].second] = j;
		}
		
		vector<int>lcp(n);
		int k = 0;
		for(int i = 0; i<n-1; i++){
			int ind1 = indices[i];
			int ind2 = arr[ind1-1].second;
			while(ss[i+k]==ss[ind2+k])k++;
			lcp[ind1-1] = k;
			k = max(k-1,0LL);
		}
		for(int i = 0; i<n; i++){
			arr[i].second++;
		}
		n--;
		vector<vector<int>>val(n+1,vector<int>(n+1));
		for(int i = 1; i<n; i++){
			int v = (int)1e18;
			for(int j = i+1; j<=n; j++){
				v = min(v,lcp[j-1]);
				val[arr[i].second][arr[j].second] = val[arr[j].second][arr[i].second] = v;
			}
		}
		//cout << "\n";
		vector<int>dp(n+1);
		int ans = 0;
		for(int i = 1; i<=n; i++){
			int mx = n-i+1;
			for(int j = 1; j<i; j++){
				if(s[j-1]>s[i-1])continue;
				if(s[j-1]<s[i-1]){
					mx = max(mx,n-i+1+dp[j]);
					continue;
				}
				int high = val[i][j];
				if(high==n-i+1)continue;
				if(s[j+high-1]<s[i+high-1]){
					mx = max(mx,dp[j]+n-i+1-high);
				}
			}
			dp[i] = mx;
			ans = max(ans,dp[i]);
		}
		cout << ans << "\n";
	}
	return 0;
}