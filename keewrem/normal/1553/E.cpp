#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;



void solve(){
	int N,K; cin >> N >> K;
	vi v(N); for(auto &x: v){cin >> x; x--;}
	vi cnt(N,0);
	for(int i = 0; i < N; i++){
		cnt[(i-v[i]+N)%N]++;
	}
	vi ps;
	for(int i = 0; i < N; i++)if(cnt[i] >= N-2*K)ps.pb(i);
	vi ans;
	for(auto x: ps){
		vi vis(N,0);
		int tot = 0;
		for(int i = 0; i < N; i++){
			if(vis[i])continue;
			vis[i] = 1;
			int c = (v[i]+x)%N;
			while(c != i){
				vis[c] = 1;
				c = (v[c]+x)%N; tot++;
			}
		}
		if(tot <= K)ans.pb(x);
	}
	cout << ans.size();
	for(auto x: ans)cout << " " << x;
	cout << endl;
  	return;
}

int main(){
  int T;
    cin >> T;
    while(T--){
        solve();
    }
}