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
		string s; cin >> s;
		int mid = n / 2;
		int L = mid, R = mid;
		while(L - 1 >= 0 && s[L - 1] == s[mid]) L--;
		while(R +1 < n && s[R + 1] == s[mid]) R++;
		cout << R - L + 1 << endl;
	}
}