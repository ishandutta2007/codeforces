#include <bits/stdc++.h>
using namespace std;
#define ll int
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
const int N = 1005;
int a[N];
multiset<int> values;
int main(){
	int t = 1, n;
	// sd(t);
	while(t--){
		sd(n);
		for(int i = 1; i <= n; i++){
			sd(a[i]);
			values.insert(a[i]);
		}
		ll c0 = values.count(0), ans = 2;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(i == j) continue;
				ll x = a[i], y = a[j];
				if(x == 0 && y == 0){
					ans = max(ans, c0);
					continue;
				}
				int l = 2;
				vector<int> deletions; deletions.pb(x); deletions.pb(y);
				values.erase(values.find(x)); values.erase(values.find(y));
				while(1){
					ll temp = y;
					y += x;
					x = temp;
					if(y > 1e9 || values.find(y) == values.end()) break;
					l++;
					if(l <= 10){
						values.erase(values.find(y));
						deletions.pb(y);
					}
				}
				for(int x : deletions) values.insert(x);
				ans = max(ans, l);
			}
		}
		printf("%d\n", ans);
	}
}