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
#endif

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		if(k > (n - 1) / 2){
			cout << -1 << endl;
			continue;
		}
		int L = 1, R = n;
		for(int i = 1; i <= n; i++){
			if(!k || i % 2 == 1) cout << (L++) << " ";
			else{
				cout << (R--) << " ";
				k--;
			}
		}
		cout << endl;
	}
}