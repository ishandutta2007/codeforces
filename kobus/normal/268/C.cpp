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
#define INF LLONG_MAX/4
#define MOD 1000000007


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,m;
	cin>>n>>m;

	cout<<min(n,m)+1<<endl;

	for(int i=0;i<=min(n,m);i++){
		cout<<i<<" "<<m-i<<endl;
	}

	return 0;
}