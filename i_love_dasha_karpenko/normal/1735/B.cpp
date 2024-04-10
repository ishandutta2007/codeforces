#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 107;
int A[N];
void solve(){
	int n;
	cin>>n;
	for(int i = 1;i<=n;i+=1){
		cin>>A[i];
	}
	sort(A+1,A+1+n);
	ll res = 0;
	int mx = A[1]*2-1;
	// A[i]/x == mx
	// x = A[i]/mx
	for(int i = 2;i<=n;i+=1){
		int parts = A[i]/mx;
		while(parts==0 || A[i]/parts + (A[i]%parts!=0) > mx){
			parts += 1;
		}
		while(parts>1 && A[i]/(parts-1)+(A[i]%(parts-1)!=0)<=mx){
			parts -= 1;
		}
		res += parts-1;
	}
	cout<<res<<endl;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	cin>>t;
	while(t--){
		solve();
	}
}