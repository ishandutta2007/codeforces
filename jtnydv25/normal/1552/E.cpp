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
#define endl '\n'
#endif

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t = 1; 
	// cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		vector<int> c(n * k), a(n), b(n);
		for(int i = 0; i < n * k; i++){
			cin >> c[i];
			c[i]--;
		}
		int done = 0;
		vector<bool> D(n);
		while(done < n){
			for(int j = 0; j + 1 < k && done < n; j++){
				vector<int> old(n, -1);
				for(int i = 0; i < n * k; i++){
					int color = c[i];
					if(D[color]) continue;
					if(old[color] != -1){
						int v = i, u = old[color];
						a[color] = u;
						b[color] = v;
						D[color] = true;
						fill(all(old), -1);
						done++;
					}
					else old[color] = i;
				}
			}
		}
		for(int i = 0; i < n; i++) cout << a[i] + 1 << " " << b[i] + 1 << endl;
	}
}