#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int>ind; ind.push_back(-1);
	vector<int>ind2; ind2.push_back(-1);
	for(int i = 0; i<n; i++){
		if(s[i]=='A')ind.push_back(i);
		else ind2.push_back(i);
	}
	ind.push_back(n);
	ind2.push_back(n);
	int ans = 0;
	for(int i = 0; i<n; i++){
		if(s[i]=='A'){
			int v = *--lower_bound(ind.begin(),ind.end(),i);
			ans+=i-v;
			v = *upper_bound(ind.begin(),ind.end(),i);
			ans+=v-i;
			ans--;
			if(i<n-1&&s[i+1]=='B')ans--;
		}
		if(s[i]=='B'){
			int v = *--lower_bound(ind2.begin(),ind2.end(),i);
			ans+=i-v;
			v = *upper_bound(ind2.begin(),ind2.end(),i);
			ans+=v-i;
			ans--;
			if(i<n-1&&s[i+1]=='A')ans--;
		}
	}

	cout << n*(n+1)/2 - ans << "\n";
	return 0;
}