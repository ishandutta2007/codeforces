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
		int n; cin >> n;
		vector<string> A(3);
		vector<int> cnt(3);
		vector<int> perm(3);
		for(int i = 0; i < 3; i++){
			cin >> A[i];
			for(int j = 0; j < 2 * n; j++) cnt[i] += A[i][j] == '1';
			perm[i] = i;
		}
		sort(all(perm), [&](int i, int j){return cnt[i] < cnt[j];});
		int u = 0, v = 0;
		char c = '0';
		if(cnt[perm[1]] <= n){
			u = perm[0], v = perm[1]; c = '0';
		} else{
			u = perm[1]; v = perm[2]; c = '1';
		}
		int i = 0, j = 0;
		// trace(A[u], A[v]);
		while(i < 2 * n || j < 2 * n){
			char x = i < 2 * n ? A[u][i] : c;
			char y = j < 2 * n ? A[v][j] : c;
			// trace(i, j, x, y);
			if(x == y){
				cout << x; i++; j++;
			} else{
				cout << (char)('0' + '1' - c);
				if(x != c) i++;
				else j++;
			}
		}
		cout << "\n";
	}
}