#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		int mn = 0;
		int cur = 0;
		for(int i = 0; i<n; i++){
			if(s[i]=='('){
				cur++;
			}
			else{
				cur--;
			}
			mn = min(mn,cur);
		}
		cout << -1*mn << "\n";
	}
	return 0;
}