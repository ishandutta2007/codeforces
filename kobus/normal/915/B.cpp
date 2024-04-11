#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
#define MAXN 3123
#define INF LLONG_MAX
#define MOD 1000000007

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,p,l,r;
	cin>>n>>p>>l>>r;

	if(l==1 && r==n)cout<<0<<endl;
	else if(r==n){
		cout<<1+abs(l-p)<<endl;
	}
	else if(l==1){
		cout<<1+abs(r-p)<<endl;
	}
	else cout<<2+r-l+min(abs(p-l),abs(p-r))<<endl;
	

  	return 0;

}