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
		int cnt = 0;
		for(char nxt: s){
			cnt+=nxt-'a'+1;
		}
		if(s.size()%2==0){
			cout << "Alice " << cnt << "\n";
			continue;
		}
		cnt-=2*(min(s[0],s[s.size()-1])-'a'+1);
		if(cnt<0){
			cout << "Bob " << abs(cnt) << "\n";
		}
		else{
			cout << "Alice " << cnt << "\n";
		}
	}
	return 0;
}