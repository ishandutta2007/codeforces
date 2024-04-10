#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
const int LOG = 31;
const int cst = 20;
map<int,int> M[LOG][4];
int pr[LOG];
void solve() {
	int n;
	cin>>n;
	int res = 0;
	for(int i = 0;i<n;i+=1){
		int val;
		cin>>val;
		int pref = 0;
		int ans = 0;
		for(int lg = LOG-1;lg>=0;lg-=1){
			bool cbit = (pr[lg]&i)!=0;
			bool obit = (pr[lg]&val)!=0;
			// check cbit^a[oth]&(1<<bit) == 0 and obit^oth&(1<<bit)==1
			if (lg<cst && M[lg][(1-obit)+2*cbit].count(pref)){
				ans = max(ans,M[lg][(1-obit)+2*cbit][pref]);
			}
			// check cbit^a[oth]&(1<<bit) == obit^a[cur]&(1<<bit)
			// means a[oth]^obit == cbit^a[cur]
			pref ^= (cbit^obit)?pr[lg]:0;
		}
//		if (i==1)
//			exit(0);
		ans += 1;
		pref = 0;
		for(int lg = LOG-1;lg>=0;lg-=1){
			int cr = (i>>lg)%2+2*((val>>lg)%2);
			if (lg<cst){
				M[lg][cr][pref] = max(M[lg][cr][pref],ans);
			}
			pref ^= (1<<lg) & (i^val);
		}
		res = max(res,ans);
	}
	cout<<res<<endl;
	for(int i = 0;i<LOG;i+=1){
		for(int j = 0;j<4;j+=1){
			M[i][j].clear();
		}
	}
}
signed main(){
	pr[0] = 1;
	for(int i = 1;i<LOG;i+=1){
		pr[i] = pr[i-1]*2;
	}
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--)
        solve();
}