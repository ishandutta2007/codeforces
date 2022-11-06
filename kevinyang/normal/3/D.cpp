#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	cin >> s;
	int n = s.length();
	if(n%2==1){
		cout << "-1\n";
		return 0;
	}
	vector<pair<int,int>>arr(n);
	int inf = 1e12;
	int ans = 0;
	for(int i = 0; i<n; i++){
		if(s[i]=='('){
			arr[i] = {0,inf};
		}
		else if(s[i]==')'){
			arr[i] = {inf,0};
		}
		else{
			int a,b;
			cin >> a >> b;
			arr[i] = {a,b};
		}
		ans+=arr[i].second;
		s[i] = ')';
	}
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	for(int i = 0; i<n; i+=2){
		pq.push({arr[i].first-arr[i].second,i});
		pair<int,int>p = pq.top();
		pq.pop();
		ans+=p.first;
		s[p.second] = '(';
		pq.push({arr[i+1].first-arr[i+1].second,i+1});
	}
	if(ans>1e11){
		cout << "-1\n";
		return 0;
	}
	cout << ans << "\n";
	cout << s << "\n";
	return 0;
}