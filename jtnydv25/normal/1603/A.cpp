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
		vector<int> a(n);
		for(int i = 0; i < n; i++) cin >> a[i];
		for(int k = 0; k < n; k++){
			bool found = false;
			for(int i = n - k - 1; i >= 0; i--){
				if(a[i] % (i + 2) != 0){
					for(int j = i; j < n - k - 1; j++) a[j] = a[j + 1];
					found = true;
					break;
				}
			}
			if(!found){
				cout << "NO\n";
				goto done;
			}

		}
		cout << "YES\n";
		done:;
	}
}