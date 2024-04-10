#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		int m = n/2;
		int l = 0; int r = 0;
		while(m+1<s.size()&&s[m+1]==s[m]){
			m++;
		}
		r = m;
		while(m>0&&s[m-1]==s[m]){
			m--;
		}
		l = m;
		cout << r-l+1 << "\n";
	}
	return 0;
}