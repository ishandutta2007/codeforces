#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 1e5+7;
vector<int> V[2];
int A[N];
void solve(){
	int n;
	cin>>n;
	for(int i = 1;i<=n;i+=1){
		cin>>A[i];
	}
	ll sum = 0;
	for(int i = 1;i<=n;i+=1){
		int val;
		cin>>val;
		V[A[i]].push_back(val);
		sum += val;
	}
	sort(V[0].begin(),V[0].end(),greater<int>());
	sort(V[1].begin(),V[1].end(),greater<int>());
	ll ans = 0;
	for(int c = 0;c<2;c+=1){
		swap(V[0],V[1]);
		int en = min(int(V[0].size()),int(V[1].size())-1);
		ll res = sum;
		for(int i = 0;i<en;i+=1){
			res += V[0][i]+V[1][i];
		}	
		if (0<=en && V[0].size()>en){
			res += V[0][en];
		}
		ans = max(ans,res);
	}
	cout<<ans<<endl;
	V[0].clear();
	V[1].clear();
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	cin>>t;
	for(int tt = 1;tt<=t;tt+=1){
		solve();
	}
}