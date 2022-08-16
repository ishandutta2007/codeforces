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
		if(n==1 || s[0] <= s[1]){
			cout << s[0]<<s[0]<<endl;
			continue;
		}

		int j = 1;

		for(int i = 2; i < n; i++){
			if(s[i] <= s[i - 1]){
				j = i;
			} else break;
		}
		string u = s.substr(0, j + 1);
		cout << u;
		reverse(all(u));
		cout << u << endl;
	}
}