#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define div dsfd
typedef long long ll;
const int N = 2e5+7;
const ll INF = 1e18;
ll A[N];
void solve(){
	int n;
	cin>>n;
	for(int i = 1;i<=n;i+=1){
		cin>>A[i];
	}
	sort(A+1,A+1+n);
	ll res = 0;
	for(int i = n;i>=3;i-=1){
		res = max(res,A[i]*2-A[i-1]-A[1]);
	}
	for(int i = 1;i<=n-2;i+=1){
		res = max(res,A[i+1]+A[n]-A[i]*2);
	}
	cout<<res<<endl;
}
signed main(){

	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	cin>>t;
	while(t--){
		solve();
	}
}