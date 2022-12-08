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

int v[112];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,k,x;
	cin>>n>>k>>x;
	
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	sort(v,v+n);
	int resp=0;
	for(int i=0;i<n-k;i++){
		resp+=v[i];
	}
	for(int i=n-k;i<n;i++){
		resp+=min(x,v[i]);
	}
	cout<<resp<<endl;

	return 0;
}