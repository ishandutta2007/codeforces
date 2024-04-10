#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
void solve() {
	int n;
	cin>>n;
	pair<int,int> mx = {0,0};
	for(int i = 1;i<=n;i+=1){
		int cnt;
		cin>>cnt;
		mx = max(mx,{cnt,i});
	}
	cout<<mx.second<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--)
        solve();
}