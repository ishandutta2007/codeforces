#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef long double ld;
typedef __int128 big;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
const int N = 107;
int A[N];
void solve() {
	int n,k;
	cin>>n>>k;
	for(int i = 0;i<k;i+=1){
		A[i] = 0;
	}
	for(int i = 1;i<=n;i+=1){
		int val;
		cin>>val;
		A[i%k] = max(A[i%k],val);
	}
	ll res = 0;
	for(int i = 0;i<k;i+=1){
		res += A[i];
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