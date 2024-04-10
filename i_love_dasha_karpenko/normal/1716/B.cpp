#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n';
const int N = 107;
int A[N];
void solve(){
	int n;
	cin>>n;
	for(int i = 1;i<=n;i+=1){
		A[i] = i;
	}
	cout<<n<<endl;
	for(int step = 1;step<=n;step+=1){
		for(int i = 1;i<=n;i+=1){
			cout<<A[i]<<' ';
		}
		cout<<endl;
		swap(A[step],A[step+1]);
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