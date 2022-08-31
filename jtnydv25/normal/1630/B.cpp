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
		int n, k; cin >> n >> k;
		vector<int> a(n);
		vector<int> f(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
			--a[i];
			f[a[i]]++;
		}
		int i = 0, j = -1;
		int ans = n, cur = 0;
		int x, y;
		while(i < n){
			while(j < n && 2 * cur - n < k){
				j++;
				cur += f[j];
			}
			if(j != n){
				if(ans > j - i){
					ans = j - i;
					x = i; y = j;
				}
				ans = min(ans, j - i);
			}
			cur -= f[i];
			i++;
		}
		// trace(x, y, ans);
		cout << x+1 << " " << y+1 << endl;
		cur = 0;
		int l = 0, done = 0;
		for(int i = 0; i < n; i++){
			if(a[i] >= x && a[i] <= y) cur++;
			else cur--;
			if(cur > 0 && done < k - 1){
				cur = 0; done++;
				cout << l + 1 << " " << i + 1<< endl;
				l = i + 1;
			}
		}
		cout << l+1 << " " << n << endl;
	}
}