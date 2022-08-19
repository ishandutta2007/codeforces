#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long lint;
typedef pair<lint, int> pi;
const int MAXN = 300005;

int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int n, m; cin >> n >> m;
		vector<int> v(n);
		for(auto &i : v) cin >> i;
		for(int i=1; i<n; i++){
			while(v[i] && m >= i){
				m -= i;
				v[0]++;
				v[i]--;
			}
		}
		cout << v[0] << endl;
	}
}