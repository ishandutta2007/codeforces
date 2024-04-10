#include <bits/stdc++.h>
using namespace std;
#define int long long
bool comp(char a, char b){
	if(a=='b'&&b=='c'){
		return a>b;
	}
	if(a=='c'&&b=='b'){
		return a>b;
	}
	return a<b;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		string s2;
		cin >> s2;
		if(s2=="abc"){
			int a = count(s.begin(),s.end(),'a');
			int b = count(s.begin(),s.end(),'b');
			int c = count(s.begin(),s.end(),'c');
			if(a&&b&&c){
				sort(s.begin(),s.end(),comp);
				cout << s << "\n";
			}
			else{
				sort(s.begin(),s.end());
				cout << s << "\n";
			}
		}
		else{
			sort(s.begin(),s.end());
			cout << s << "\n";
		}
	}
	return 0;
}