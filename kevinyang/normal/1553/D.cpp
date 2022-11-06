#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int q;
	cin >> q;
	while(q--){
		string s;
		cin >> s;
		string t;
		cin >> t;
		bool f = false;
		int cur = t.length()-1;
		int prev = s.length();
		for(int i = s.length()-1; i>=0; i--){
			if(cur<0)break;
			if(s[i]==t[cur]&&(prev-i)%2==1){
				prev = i;
				cur--;
			}
		}
		if(cur==-1)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}