#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long lint;
typedef pair<lint, int> pi;
const int MAXN = 300005;

lint a[MAXN];

int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int n, m; cin >> n >> m;
		vector<int> v(n);
		int ans = 1e9;
		for(auto &i : v){
			scanf("%d",&i);
			if(i == m) ans = 1;
		}
		int mx = *max_element(all(v));
		ans = min(ans, max(2, (m+mx-1)/mx));
		cout << ans << endl;;
	}
}