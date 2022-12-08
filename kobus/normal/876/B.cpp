#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 1123456
#define INF INT_MAX/2
#define MOD 1000000

vector<int> v[112345];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,k,m;
	cin>>n>>k>>m;

	for(int i=0;i<n;i++){
		int y;
		cin>>y;
		v[y%m].pb(y);
	}

	for(int i=0;i<m;i++){
		if(v[i].size()>=k){
			cout<<"Yes\n";
			for(int j=0;j<k;j++){
				cout<<v[i][j]<<" ";
			}
			cout<<endl;
			return 0;
		}
	}

	cout<<"No"<<endl;


	return 0;
}