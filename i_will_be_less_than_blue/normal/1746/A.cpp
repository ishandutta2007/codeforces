#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 57;
int A[N];
void solve(){
	int n,k;
	cin>>n>>k;
	for(int i = 1;i<=n;i+=1){
		cin>>A[i];
	}
	bool flag = 0;
	for(int i = 1;i<=n;i+=1){
		if (A[i]==1){
			flag = 1;
			break;
		}
	}
	cout<<(flag?"YES\n":"NO\n");
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	cin>>t;
	for(int tt = 1;tt<=t;tt+=1){
		solve();
	}
}