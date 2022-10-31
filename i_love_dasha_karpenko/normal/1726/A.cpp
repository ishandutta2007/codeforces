//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n';
const int N = 2007;
int A[N];
void solve(){
	int n;
	cin>>n;
	for(int i = 1;i<=n;i+=1){
		cin>>A[i];
	}
	int res = A[n]-A[1];
	for(int i = 2;i<=n;i+=1){
		res = max(res,A[i]-A[1]);
	}
	for(int i = 1;i<n;i+=1){
		res = max(res,A[n]-A[i]);
	}
	for(int i = 2;i<=n;i+=1){
		int npos = i+n-1;
		if (npos>n){
			npos -= n;
		}
		res = max(res,A[npos]-A[i]);
	}
	cout<<res<<endl;
}
signed main(){

	ios_base::sync_with_stdio(0); cin.tie(0);
	int tt = 1;
	cin>>tt;
	while(tt--){
		solve();
	}
}