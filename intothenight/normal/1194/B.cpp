#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int qq;
	cin >> qq;
	while(qq --){
		int n, m;
		cin >> n >> m;
		vector<string> s(n);
		for(auto &x: s){
			cin >> x;
		}
		vector<int> col(m), row(n);
		for(int i = 0; i < n; i ++){
			for(int j = 0; j < m; j ++){
				row[i] += (s[i][j] == '*');
				col[j] += (s[i][j] == '*');
			}
		}
		int res = n + m;
		for(int i = 0; i < n; i ++){
			for(int j = 0; j < m; j ++){
				res = min(res, n + m - 1 - row[i] - col[j] + (s[i][j] == '*'));
			}
		}
		cout << res << "\n";
	}
	return 0;
}