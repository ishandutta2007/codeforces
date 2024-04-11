#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAXN 112345
#define INF INT_MAX
#define MOD 1000000007
#define pii pair<int,int>
#define double long double 
#define int long long	

																																																																																										

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	int n,m;
	cin>>n>>m;
	vector<string> a;
	vector<string> b;
	for(int i=0;i<n;i++){
		string x;
		cin>>x;
		a.pb(x);
	}
	for(int i=0;i<m;i++){
		string x;
		cin>>x;
		b.pb(x);
	}
	int q;
	cin>>q;
	while(q--){
		int y;
		cin>>y;
		y--;
		cout<<a[y%n]<<b[y%m]<<endl;
	}	

	return 0;
}