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
#define MOD 1000000007

int v[312345];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	sort(v,v+n);
	int ans=0;
	for(int i=0;i<n/2;i++){
		ans+=(v[i]+v[n-i-1])*(v[i]+v[n-i-1]);
	}
	cout<<ans<<endl;

	return 0;
}