//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n';
const int N = 2e5+7;
int B[N];
pair<int,int> A[N],ans[N];
void solve(){
	int n;
	cin>>n;
	for(int i = 1;i<=n;i+=1){
		cin>>A[i].first;
		A[i].second = i;
	}
	sort(A+1,A+1+n);
	for(int i = 1;i<=n;i+=1){
		cin>>B[i];
	}
	int ptr = 1;
	for(int i = 1;i<=n;i+=1){
		while(ptr<=n && B[ptr]<A[i].first){
			ptr += 1;
		}
		ans[A[i].second].first = B[ptr]-A[i].first;
	}
	int last = n+1;
	for(int i = n;i>=1;i-=1){
		ans[A[i].second].second = B[last-1]-A[i].first;
		if (B[i-1]<A[i].first){
			last = i;
		}
	}
	for(int i = 1;i<=n;i+=1){
		cout<<ans[i].first<<' ';
	}
	cout<<endl;
	for(int i = 1;i<=n;i+=1){
		cout<<ans[i].second<<' ';
	}
	cout<<endl;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tt = 1;
	cin>>tt;
	while(tt--){
		solve();
	}
}