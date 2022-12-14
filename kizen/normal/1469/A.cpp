#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while(T--){
		string s;
		cin >> s;
		int l = 0, r = 0, f = 0;
		for(int i = 0; i < (int)s.size(); ++i){
			if(s[i] == '('){
				++l, ++r;
			}
			else if(s[i] == ')'){
				--l, --r;
			}
			else{
				--l, ++r;
			}
			if(r < 0){
				f = 1;
			}
			l = max(l, 0);
		}
		if(f || l > 0|| (int)s.size() % 2){
			cout << "NO\n";
		}
		else{
			cout << "YES\n";
		}
	}
	return 0;
}