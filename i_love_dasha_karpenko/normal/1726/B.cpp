//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n';
const int N = 2007;
void solve(){
	int n,m;
	cin>>n>>m;
	if (n>m){
		cout<<"No\n";
		return;
	}
	if (m%n==0){
		cout<<"Yes\n";
		for(int i = 1;i<=n;i+=1){
			cout<<m/n<<' ';
		}
		cout<<endl;
		return;
	}
	if (n%2==0 && m%2!=0){
		cout<<"No\n";
		return;
	}
	if (n%2!=0){
		cout<<"Yes\n";
		for(int i = 1;i<n;i+=1){
			cout<<1<<' ';
			m-=1;
		}
		cout<<m<<endl;
		return;
	}
	else{
		cout<<"Yes\n";
		for(int i = 1;i<n-1;i+=1){
			cout<<1<<' ';
			m -= 1;
		}
		cout<<m/2<<' '<<m/2<<endl;
		return;
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