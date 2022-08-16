#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...) // remove in interactive
#define endl '\n'
#endif

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		string s; cin >> s;
		if(is_sorted(all(s))){
			cout << 0 << endl;
			continue;
		}
		cout << 1 << endl;
		int o = count(all(s), '1'), z = 0;
		for(int i = n - 2; i >= 0; i--){
			if(s[i + 1] == '0'){
				z++;
			} else o--;
			if(o == z){
				vector<int> pos;
				for(int r = 0; r <= i; r++) if(s[r] == '1') pos.push_back(r);
				for(int r = i + 1; r < n; r++) if(s[r] == '0') pos.push_back(r);
				cout << pos.size() << " ";
				for(auto it: pos) cout << it+1 <<" ";
				cout << endl;
				break;
			}
		}
	}
}