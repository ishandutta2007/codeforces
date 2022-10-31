#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
const int N = 120*120*2;
vector<int> G[N];
ll clk[N];
void calc(ll steps){
	int n = 120*120;
	for(int i = 0;i<n;i+=1){
		clk[i] = 0;
	}
	clk[0] = steps+1;
	for(int i = 0;i<n;i+=1){
		clk[G[i][0]] += clk[i]/2 + clk[i]%2;
		clk[G[i][1]] += clk[i]/2;
	}
}

void solve() {
	int n = 120;
	for(int i = 0;i<n;i+=1){
		for(int j = 0;j<n;j+=1){
			if (j+1<n){
				G[i*n+j].push_back(i*n+j+1);
			}
			else{
				G[i*n+j].push_back(N-1);
			}
			G[i*n+j].push_back((i+1)*n+j);
		}
	}
	int q;
	cin>>q;
	for(int qe = 1;qe<=q;qe+=1){
		ll t;
		int x,y;
		cin>>t>>x>>y;
		t -= x+y;
		if (t<0){
			cout<<"NO\n";
			continue;
		}
		calc(t);
		ll ans = clk[x*n+y];
//		cout<<"GDB "<<clk[x*n+y]<<endl;
		calc(t-1);
		ans -= clk[x*n+y];
//		cout<<"GDB "<<clk[x*n+y]<<endl;
		if (ans){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
//    cin>>t;
    while(t--){
	    solve();
    }
}