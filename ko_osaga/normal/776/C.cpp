#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long lint;

int n, k;
lint a[100005];
set<lint> s;

lint solve(lint x){
	map<lint, int> mp;
	lint ret = 0;
	for(int i=1; i<=n; i++){
		mp[a[i-1]]++;
		if(mp.find(a[i] - x) != mp.end()){
			ret += mp[a[i] - x];
		}
	}
	return ret;
}

int main(){
	scanf("%d %d",&n,&k);
	if(k == 1){
		s.insert(1);
	}
	else if(k == -1){
		s.insert(-1);
		s.insert(1);
	}
	else{
		lint ans = 1;
		while(abs(ans) <= 1e15){
			s.insert(ans);
			ans *= k;
		}
	}
	for(int i=1; i<=n; i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1; i<=n; i++) a[i] += a[i-1];
	lint ans = 0;
	for(auto &i : s){
		ans += solve(i);
	}
	cout << ans;
}