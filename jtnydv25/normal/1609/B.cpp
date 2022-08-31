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
	int n, q;
	cin >> n >> q;
	string s; cin >> s;
	auto contribution = [&](int p){
		return p > 0 && p + 1 < n && s[p - 1] == 'a' && s[p] == 'b' && s[p + 1] == 'c';
	};
	int sum = 0;
	for(int i = 0; i < n; i++) sum += contribution(i);
	while(q--){
		int p; char c;
		cin >> p >> c;
		p--;
		sum -= contribution(p) + contribution(p - 1) + contribution(p + 1);
		s[p] = c;
		sum += contribution(p) + contribution(p - 1) + contribution(p + 1);
		cout << sum << endl;
	}
}