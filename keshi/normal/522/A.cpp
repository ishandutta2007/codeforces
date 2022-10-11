#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

string adj(string s){
	for(int i = 0; i < s.size(); i++){
		if(s[i] >= 'A' && s[i] <= 'Z'){
			s[i] += 32;
		}
	}
	return s;
}

string a, b;
int n, ans;
map<string, int> m;

int main(){
	fast_io;
	m["polycarp"] = 1;
	cin >> n;
	while(n--){
		cin >> a >> b >> b;
		a = adj(a);
		b = adj(b);
		m[a] = m[b] + 1;
		ans = max(ans, m[a]);
	}
	cout << ans;
	return 0;
}