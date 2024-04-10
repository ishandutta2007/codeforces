#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define vll vector<ll >
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1)
#define all(a) (a).begin(), (a).end()
#define print(s) cerr<<#s<<" : ";for(auto i:(s))cerr<<i<<" ";cerr<<"\n";
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define endl "\n"
string rot(string s, int k){
	string ret = s;
	int n = s.length();
	for(int i = 0; i < n; i++) ret[i] = s[(i + k) % n];
		return ret;
}
string s[55];
const int inf = 1e7;
int main(){
	int t = 1, n;
	// sd(t);
	while(t--){
		int n;
		cin >> n;
		set<int> lens;
		for(int i = 0; i < n; i++){
			cin >> s[i];
			lens.insert(s[i].length());
		}
		// cerr << lens.size() << endl;
		if(lens.size() > 1){
			cout << -1;
			return 0;
		}
		int m = s[0].length();
		int ans = inf;
		for(int k = 0; k < m; k++){
			int ans1 = 0;
			string val = rot(s[0], k);
			for(int i = 0; i < n; i++){
				bool flag = 0;
				for(int k1 = 0; k1 < m; k1++){
					if(rot(s[i], k1) == val){
						ans1 += k1;
						flag = 1;
						break;
					}
				}
				if(!flag) ans1 += inf;
			}
			ans = min(ans, ans1);
		}
		if(ans >= inf) ans = -1;
		cout << ans;
	}
}