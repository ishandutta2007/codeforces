#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N = 2e5+7;
int A[N];
void solve(){
	int n;
	cin>>n;
	int sz = 0;
	for(int i = 1;i<=n;i+=1){
		cin>>A[i];
		sz += A[i]!=0;
	}
	if (sz%2==1){
		cout<<"-1\n";
		return;
	}
	vector<pair<int,int> > ans;
	for(int i = 1;i<=n;){
		if (A[i]==0){
			ans.push_back({i,i});
			i += 1;
			continue;
		}
		int nxt = i+1;
		while(A[nxt]==0){
			nxt += 1;
		}
		if (A[i]==A[nxt]){
			if (i+1==nxt){
				ans.push_back({i,i+1});
			}
			else{
				ans.push_back({i,nxt-2});
				ans.push_back({nxt-1,nxt});
			}
		}
		else{
			ans.push_back({i,nxt-1});
			ans.push_back({nxt,nxt});
		}
		i = nxt + 1;
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