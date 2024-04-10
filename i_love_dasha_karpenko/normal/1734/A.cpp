#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define int ll
const int N = 307;
int A[N];
void solve(){
	int n;
	cin>>n;
	for(int i = 1;i<=n;i+=1){
		cin>>A[i];
	}
	sort(A+1,A+1+n);
	int res = INT_MAX;
	for(int i = 1;i+2<=n;i+=1){
		res = min(res,A[i+2]-A[i]);
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