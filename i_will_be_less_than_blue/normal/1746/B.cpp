#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 1e5+7;
int A[N],suf[N];
void solve(){
	int n;
	cin>>n;
	int res = n;
	for(int i = 1;i<=n;i+=1){
		cin>>A[i];
	}
	suf[n+1] = 0;
	for(int i = n;i>=1;i-=1){
		suf[i] = suf[i+1] + (A[i]==0);
	}
	int cnt0 = 0;
	for(int i = 1;i<=n;i+=1){
		cnt0 += A[i]==0;
		int d1 = i-cnt0;
		int d2 = suf[i+1];
		res = min(res,d1 + max(0,d2-d1));
	}
	res = min(res,suf[1]);
	int need = n-suf[1];
	res = min(res,need);
	cout<<res<<endl;

}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	cin>>t;
	for(int tt = 1;tt<=t;tt+=1){
		solve();
	}
}