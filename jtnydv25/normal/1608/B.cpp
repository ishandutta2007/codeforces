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
		int n, a, b; cin >> n >> a >> b;
		if(max(a, b) > (n + 1) / 2 ||  (a + b) > n - 2 || max(a, b) - min(a, b) > 1){
			cout << -1 << endl;
			continue;
		}
		if(a > b){
			int L = n - (a + b + 2) + 1, R = n;
			for(int i = 1; i <= n; i++){
				if(i <= a + b + 2){
					if(i & 1){
						cout << L << " ";
						L++;
					} else{
						cout << R << " ";
						R--;
					}
				}
				else{
					cout << n - i + 1 << " ";
				}
			}
		} else{
			int L = 1, R = a + b + 2;
			for(int i = 1; i <= n; i++){
				if(i <= a + b + 2){
					if((i % 2 == 0) ^ (a == b)){
						cout << L << " ";
						L++;
					} else{
						cout << R << " ";
						R--;
					}
				}
				else{
					cout << i << " ";
				}
			}
		}
		cout << endl;
	}
}