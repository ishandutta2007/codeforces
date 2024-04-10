#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n';

void solve(){
	int n;
	cin>>n;
	if (n%2==0){
		for(int i = 1;i<=n;i+=2){
			cout<<i+1<<' '<<i<<' ';
		}
		cout<<endl;
	}
	else{
		cout<<1<<' ';
		for(int i = 2;i<=n;i+=2){
			cout<<(i+1)<<' '<<i<<' ';
		}
		cout<<endl;
	}
}
signed main(){
	
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tt = 1;
	cin>>tt;
	while(tt--){
		solve();
	}
}