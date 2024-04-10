#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N = 2e5+7;
int A[N];
void solve(){
	int n;
	cin>>n;
	for(int i = 1;i<=n;i+=1){
		cin>>A[i];
	}
	if (n%2==1){
		cout<<"-1\n";
		return;
	}
	vector<pair<int,int> > ans;
	for(int i = 1;i<=n;i+=2){
		if (A[i]==A[i+1]){
			ans.push_back({i,i+1});
		}
		else{
			ans.push_back({i,i});
			ans.push_back({i+1,i+1});
		}
	}
	cout<<ans.size()<<endl;
	for(auto [x,y]:ans){
		cout<<x<<' '<<y<<endl;
	}	
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	cin>>t;
	while(t--){
		solve();
	}
}