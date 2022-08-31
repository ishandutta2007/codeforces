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
		int n, k; cin >> n >> k;
		if(k > (n + 1) / 2){
			cout << -1 << endl;
			continue;
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(k > 0 && i == j && i % 2 == 0){
					cout << 'R';
					k--;
				} else cout << '.';
			}
			cout << endl;
		}
	}
}