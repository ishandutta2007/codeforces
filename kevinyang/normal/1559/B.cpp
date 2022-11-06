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
		int v = count(s.begin(),s.end(),'?');
		if(v==n){
			for(int i = 0; i<n; i++){
				if(i%2==0)cout << "B";
				else cout << "R";
			}
			cout << "\n";
			continue;
		}
		else{
			int idx = 0;
			for(int i = 0; i<n; i++){
				if(s[i]!='?'){
					idx = i;
					break;
				}
			}
			for(int i = idx-1; i>=0; i--){
				if(s[i]!='?')continue;
				if(s[i+1] == 'R')s[i] = 'B';
				if(s[i+1] == 'B')s[i] = 'R';
			}
			for(int i = idx+1; i<n; i++){
				if(s[i]!='?')continue;
				if(s[i-1]=='R')s[i] = 'B';
				if(s[i-1]=='B')s[i] = 'R';
			}
			cout << s << "\n";
		}
	}
	return 0;
}