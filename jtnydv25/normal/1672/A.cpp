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
		int n; cin >> n;
		int s = 0;
		for(int i = 0; i < n; i++){
			int x; cin >> x;
			s ^= (x + 1) & 1;
		}
		cout << (s == 0 ? "maomao90": "errorgorn") << endl;
	}
}