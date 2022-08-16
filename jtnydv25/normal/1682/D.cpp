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

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	while(t--){
		int n; string s; cin >> n >> s;
		int odd = count(all(s), '1');
		if(odd == 0 || odd % 2 == 1){
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		int head = -1;
		for(int i = 0; i < n; i++){
			int j = (i + 1) % n;
			if(s[i] == '0') cout << (i + 1) <<" " << (j + 1) << endl;
			else if(head != -1) cout << (head + 1) << " " << (j + 1) << endl;
			else head = j;
		}
	}
}