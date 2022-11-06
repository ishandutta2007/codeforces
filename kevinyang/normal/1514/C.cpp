#include <bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int a, int b){
	if(b==0)return a;
	return gcd(b,a%b);
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	int cur = 1;
	vector<int>ans;
	for(int i = 1; i<=n; i++){
		if(gcd(i,n)==1){
			ans.push_back(i);
			cur*=i; cur%=n;
		}
	}
	int bad = cur;
	cout << ans.size()-(bad>1) << "\n";
	for(int nxt: ans){
		if(nxt==bad&&nxt>1)continue;
		cout << nxt << " ";
	}
	cout << "\n";
	return 0;
}