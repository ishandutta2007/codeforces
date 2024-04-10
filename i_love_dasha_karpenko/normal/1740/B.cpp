#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define div dsfd
typedef long long ll;
const ll INF = 1e18;
const int N = 2e5+7;
pair<int,int> A[N];
void solve(){
	int n;
	cin>>n;
	ll mx = 0;
	ll res = 0;
	for(int i = 1;i<=n;i+=1){
		cin>>A[i].first>>A[i].second;
		if (A[i].first<A[i].second){
			swap(A[i].first,A[i].second);
		}
		res += A[i].second;
	}
	sort(A+1,A+1+n,greater<pair<int,int>>());
	ll ans = INF;
	int lim = 0;
	for(int i = 1;i<=n;i+=1){
		if (A[i].first<lim){
			break;
		}
		ans = min(ans,res + A[i].first);
//		cout<<(res+A[i].first)*2<<' '<<res<<' '<<A[i].first<<endl;
		res += A[i].first-A[i].second;
		lim = max(lim,A[i].second);
	}
	cout<<ans*2<<endl;
}
signed main(){

	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	cin>>t;
	while(t--){
		solve();
	}
}