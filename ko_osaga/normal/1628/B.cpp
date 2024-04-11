#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<string> s(n);
		bool ok = 0;
		for(auto &i : s){
			cin >> i;
			string j = i;
			reverse(all(j));
			if(j == i) ok = 1;
		}
		{
			map<string, bool> chk;
			bool alpha[26] = {};
			for(auto &i : s){
				auto r = i; reverse(all(r));
				if(chk.count(r)) ok = 1;
				if(sz(r) > 1 && chk.count(r.substr(0, sz(r) - 1))) ok = 1;
				for(int j = 0; j < 26; j++){
					if(chk.count(r + string(1, j + 'a'))) ok = 1;
				}
				if(sz(i) == 1) alpha[i[0] - 'a'] = 1;
				if(sz(i) == 3){
					for(int j = 0; j < 26; j++){
						if(alpha[j]) chk[string(1, j + 'a') + i.substr(0, 2)] = 1;
					}
				}
				chk[i] = 1;
			}
		}
		cout << (ok ? "YES\n" : "NO\n");
	}
}