#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pp;
#define endl '\n';
const int N = 1e5+7;	
const int MX = 1e9;
int n,k,A[N],vis[N];
pair<int,int> B[N];
void solve(){
	cin>>n>>k;
	for(int i = 1;i<=n;i+=1){
		cin>>A[i];
		B[i] = {A[i],i};
		vis[i] = 0;
	}
	vis[n+1] = 0;
	sort(B+1,B+1+n);
	B[n+1] = {1e9,0};
	int ps = 1;
	while(ps<=n && B[ps].first<B[k].first){
		vis[B[ps].second] = 1;
		ps += 1;
	}
	int last = k;
	for(int i = ps;i<=n;i+=1){
		if (B[i].first!=B[k].first){
			break;
		}
		last = i;
		vis[B[i].second] = 2;
	}
	bool flag = 0;
	int mx = 0,mxx;
	for(int i = 1;i<=n;i+=1){
		mxx = max(mxx,A[i]);
		if (i<n){
			mx = max(mx,min(A[i],A[i+1]));
		}
		if (!vis[i] && (vis[i-1] || vis[i+1])){
			mx = max(mx,A[i]);
		}
		if ((vis[i]==1 || vis[i+1]==1) && vis[i] && vis[i+1]){
			flag = 1;
		}
		if (k-ps+1>=2 && vis[i] && vis[i+1]){
			flag = 1;
		}
	}
	int res = min(B[k+1].first*2,mx);
	if (flag){
		res = max(res,min(B[k+1].first*2,MX));
	}
	if (k>1){
		res = max(res,min(B[k].first*2,MX));
	}
	res = max(res,min(B[k].first*2,mxx));
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