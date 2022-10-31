//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n';
const int N = 1e5+7;
int A[N],B[N];
bool Check(int n,int mask){
	map<int,int> M;
	for(int i = 1;i<=n;i+=1){
		M[B[i]&mask] += 1;
	}
	for(int i = 1;i<=n;i+=1){
		int num = A[i]&mask;
		if (M[mask^num]==0){
			return false;
		}
		M[mask^num] -= 1;
	}
	return true;
}
void solve(){
	int n;
	cin>>n;
	for(int i = 1;i<=n;i+=1){
		cin>>A[i];
	}
	for(int i = 1;i<=n;i+=1){
		cin>>B[i];
	}
	int ans = 0;
	for(int bit = 30;bit>=0;bit-=1){
		ans += (1<<bit);
		if (!Check(n,ans)){
			ans -= 1<<bit;
		}
	}
	cout<<ans<<endl;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tt = 1;
	cin>>tt;
	while(tt--){
		solve();
	}
}