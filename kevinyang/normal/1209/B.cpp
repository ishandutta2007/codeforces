#include <bits/stdc++.h>
using namespace std;
#define int long long
char oppo(char ch){
	if(ch=='0')return '1';
	else return '0';
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<pair<int,int>>arr(n);
	for(int i = 0; i<n; i++){
		cin >> arr[i].first >> arr[i].second;
	}
	int ans = count(s.begin(),s.end(),'1');
	for(int i = 1; i<=1000; i++){
		for(int j = 0; j<n; j++){
			if(i>=arr[j].second&&(i-arr[j].second)%arr[j].first==0){
				s[j] = oppo(s[j]);
			}
		}
		ans = max(ans,(int)count(s.begin(),s.end(),'1'));
	}
	cout << ans << "\n";
	return 0;
}