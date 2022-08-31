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

void solve(){
	int n; cin >> n;
	vector<int> a(n);
	for(int& x: a) cin >> x;
	for(int h = 0; h < 2; h++){
		int i = 0, j = n - 1;
		int x = -1;
		bool error = false;
		while(j > i){
			if(a[i] == a[j]){
				i++;
				j--;
				continue;
			}
			if(x == -1){
				if(h){
					x = a[i];
				} else{
					x = a[j];
				}
				// trace(h, x);
			}
			if(a[i] == x){
				i++;
			} else if(a[j] == x){
				j--;
			} else{
				error = true;
				break;
			}
		}
		if(error){
			continue;
		}
		cout << "YES" << endl;
		return;
	}
	cout << "NO" << endl;
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	while(t--){
		solve();		
	}
}