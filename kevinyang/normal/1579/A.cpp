#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int a = count(s.begin(),s.end(),'A');
		int b = count(s.begin(),s.end(),'B');
		int c = count(s.begin(),s.end(),'C');
		if(a+c==b)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}