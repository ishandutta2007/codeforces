#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define div dsfd
typedef long long ll;
const int N = 1e6+7;
int A[N];
bool vis[N];
void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i = 1;i<=k;i+=1){
		vis[i] = 0;
	}
	int ocup = 0;
	int ptr = 1;
	for(int i = 1;i<=k;i+=1){
		cin>>A[i];
		A[i] = k-A[i]+1;
		ocup += 1;
		vis[A[i]] = 1;	
		while(ptr<=k && vis[ptr] && ocup<n*m-2){
			ocup -= 1;
			ptr += 1;
		}
	}
	cout<<(ocup==0?"YA":"TIDAK")<<endl;
}
signed main(){

	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	cin>>t;
	while(t--){
		solve();
	}
}