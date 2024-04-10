#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n';
void solve(){
	int n;
	cin>>n;
	int bn = n/3;
	if (bn>=1){
		cout<<bn+(n%3!=0)<<endl;
	}
	else{
		if (n==2){
			cout<<1<<endl;
		}
		else if (n==1){
			cout<<2<<endl;
		}
		else{
			assert(0);
		}
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