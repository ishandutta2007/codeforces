#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int f(string pre){
	set<char>s;
	for(char nxt: pre){
		s.insert(nxt);
	}
	return (int)s.size();
}
char mnch(string pre){
	set<char>s;
	for(char nxt: pre){
		s.insert(nxt);
	}
	return *s.begin();
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	vector<int>arr;
	for(int i = 1; i<=9; i++){
		for(int j = 1; j<=10; j++){
			string s = "";
			for(int a = 0; a<j; a++){
				s+=to_string(i);
			}
			arr.push_back(stoll(s));
		}
	}
	sort(arr.begin(),arr.end());
	while(t--){
		cin >> n >> k;
		if(k==1){
			cout << *lower_bound(arr.begin(),arr.end(),n) << "\n";
			continue;
		}
		string s = to_string(n);
		if(f(s)<=k){
			cout << s << "\n";
			continue;
		}
		string cur = "";
		cur+=s[0];
		int ans = (int)1e18;
		for(int i = 1; i<s.length(); i++){
			if(s[i]=='9'){
				cur+=s[i];
				continue;
			}
			for(int j = s[i]+1; j<='9'; j++){
				string ns = cur;
				ns+=(char)j;
				if(f(ns)<k){
					for(int k = i+1; k<s.length(); k++){
						ns+="0";
					}
					ans = min(ans,stoll(ns));
				}
				else if(f(ns)==k){
					char ch = mnch(ns);
					for(int k = i+1; k<s.length(); k++){
						ns+=ch;
					}
					ans = min(ans,stoll(ns));
				}
			}
			cur+=s[i];
		}
		cout << ans << "\n";
	}
	return 0;
}