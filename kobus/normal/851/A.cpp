#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second

typedef long long ll;
typedef pair<int,int>pii;
 
#define MAXN 11234567
#define INF INT_MAX/2
#define MOD 1000000007
#define int long long


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,k,t;
	cin>>n>>k>>t;


	if(t>=k && t<=n)cout<<k<<endl;
	else if(t<k)cout<<t<<endl;
	else cout<<k+n-t<<endl;
	
	
	return 0;
}