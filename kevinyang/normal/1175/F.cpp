#include <bits/stdc++.h>
using namespace std;
#define int long long
mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count());
vector<int>h(1000005);
vector<int>pre(1000005);
int n;
vector<int>arr(1000005);
vector<int>psa(1000005);
int ans = 0;
void solve(){
	for(int i = 1; i<=n; i++){
		if(arr[i]==1){
			set<int>s;
			s.insert(1);
			for(int j = i+1; j<=n; j++){
				if(s.find(arr[j])!=s.end())break;
				s.insert(arr[j]);
				if(true){
					int len = *--s.end();
					if(j-len>=0&&pre[len]==(psa[j]^psa[j-len])){
						//cout << j << " " << len << "\n";

						ans++;
					}
				}
			}
		}
	}
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	for(int i = 1; i<=n; i++){
		h[i] = rng();
	}
	for(int i = 1; i<=n; i++){
		psa[i] = psa[i-1]^h[arr[i]];
	}
	
	for(int i = 1; i<=n; i++){
		pre[i] = pre[i-1]^h[i];
	}
	solve();
	//cout << ans << "\n";
	reverse(arr.begin()+1,arr.begin()+n+1);
	for(int i = 1; i<=n; i++){
		psa[i] = psa[i-1]^h[arr[i]];
	}
	solve();
	//cout << ans << "\n";
	ans+=count(arr.begin(),arr.end(),1);
	cout << ans << "\n";
	return 0;
}