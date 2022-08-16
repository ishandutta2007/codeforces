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
#define endl '\n'
#endif

int get(string s){
	vector<int> v = {0, 0};
	for(int i = 0; i < 10; i++){
		int turn = i % 2;
		v[i % 2] += s[i] - '0';
		vector<int> u = v;
		for(int j = i + 1; j < 10; j++){
			if(j % 2 == 0) u[0]++;
		}
		if(u[0] < u[1]) return i + 1;
		u = v;
		for(int j = i + 1; j < 10; j++){
			if(j % 2 == 1) u[1]++;
		}
		if(u[1] < u[0]) return i + 1;
	}
	return 10;
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	while(t--){
		string s;
		cin >> s;
		int ans = 10;
		for(int i = 0; i < 1024; i++){
			string t = s;
			for(int j = 0; j < 10; j++) if(s[j] == '?'){
				t[j] = (i >> j & 1) ? '0' : '1';
			}
			ans = min(ans, get(t));
		}
		cout << ans << endl;
	}
}