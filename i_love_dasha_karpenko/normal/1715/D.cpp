//#prama GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pp;
#define endl '\n';
const int N = 1e5+7;
const int SZ = 30;
vector<pair<int,int> > G[N];
int A[N],bt[N];
void solve(){
	int n,q;
	cin>>n>>q;
	for(int i = 1;i<=n;i+=1){
		bt[i] = (1<<SZ)-1;
	}
	for(int i = 1;i<=q;i+=1){
		int a,b,x;
		cin>>a>>b>>x;
		if (a==b){
			A[a] |= x;
			bt[a] &= x;
			continue;
		}
		bt[a] &= x;
		bt[b] &= x;
		if (a>b){
			swap(a,b);
		}
		G[a].push_back({b,x});
		//G[b].push_back({a,x});
	}
	
	for(int i = 1;i<=n;i+=1){
		for(auto [to,x]:G[i]){
			int need = x^(x&bt[to]);
			A[i] |= need;
		}
		if ((A[i]|bt[i])!=bt[i]){
			assert(0);
		}
		cout<<A[i]<<' ';
		for(auto [to,x]:G[i]){
			A[to] |= x^(x&A[i]);
		}
	}
	cout<<endl;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tt = 1;
//	cin>>tt;
	while(tt--){
		solve();
	}
}