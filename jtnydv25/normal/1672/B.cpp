#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...)
#define endl '\n' // remove in interactive
#endif
string get(string s){
	if(s[s.length() - 1] == 'A'){
		return "NO";
	}
	int sum = 0;
	for(int i = 0; i < s.length(); i++){
		if(s[i] == 'A') sum++;
		else sum--;
		if(sum < 0) return "NO";
	}
	return "YES";
}
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		cout <<get(s) << endl;
	}
}