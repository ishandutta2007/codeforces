#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N = 5e5+7;
const ll INF = 1e9+7;
int cnt[N],A[N];
void solve(){
	int n,x;
	cin>>n>>x;
	for(int i = 0;i<=x;i+=1){
		cnt[i] = 0;
	}
	vector<int> V;
	for(int i = 1;i<=n;i+=1){
		cin>>A[i];
		if (A[i]<x){
			cnt[A[i]] += 1;
		}
	}
	for(int i = 1;i<x;i+=1){
		int nxt = cnt[i]/(i+1);
		int cur = cnt[i]%(i+1);
		cnt[i+1] += nxt;
		if (cur>0){
			cout<<"No\n";
			return;
		}
	}
	cout<<"Yes\n";
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	//cin>>t;
	while(t--){
		solve();
	}
}