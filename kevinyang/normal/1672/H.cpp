#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,q;
	cin >> n >> q;
	vector<int>psa(n+1);
	vector<int>psa2(n+1);
	string s;
	cin >> s;
	s = " " + s;
	for(int i = 1; i<=n; i++){
		if(s[i]==s[i-1]){
			if(s[i]=='1'){
				psa[i]++;
			}
			else{
				psa2[i]++;
			}
		}
	}
	for(int i = 1; i<=n; i++){
		psa[i]+=psa[i-1];
		psa2[i]+=psa2[i-1];
	}
	while(q--){
		int l,r;
		cin >> l >> r;
		int a = psa[r]-psa[l];
		int b = psa2[r]-psa2[l];
		cout << a+b-min(a,b)+1 << "\n";
	}
	return 0;
}