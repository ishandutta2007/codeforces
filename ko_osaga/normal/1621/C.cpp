#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using llf = long double;
using pi = pair<lint, lint>;
const int MAXN = 2005;

int query(int x){
	cout << "? " << x << endl;
	int y; cin >> y; return y;
}

int main(){
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	int q; cin >> q;
	while(q--){
		int n; cin >> n;
		vector<int> perm(n + 1);
		int qryCnt = 0;
		for(int i = 1; i <= n; i++){
			if(!perm[i]){
				vector<int> queries;
				while(true){
					int x = query(i);
					queries.push_back(x);
					if(sz(queries) >= 2 && queries.back() == queries.front()) break;
				}
				for(int j = 0; j < sz(queries) - 1; j++) perm[queries[j]] = queries[j + 1];
				qryCnt += sz(queries) + 1;
			}
		}
		cout << "!";
		for(int i = 1; i <= n; i++){
			cout << " " << perm[i];
		}
		cout << endl;
	}
}