#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 11234567890123
#define INF INT_MAX/2
#define MOD 1000000007


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,k;
	cin>>n>>k;

	if(k==0||k==n)cout<<0<<" ";
	else cout<<1<<" ";

	cout<<min(2*k,n-k)<<endl;

	return 0;
}