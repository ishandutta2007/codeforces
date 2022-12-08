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

	int y,b;
	cin>>y>>b;

	int c1,c2,c3;
	cin>>c1>>c2>>c3;

	y-=(2*c1+c2);
	b-=(3*c3+c2);

	//cout<<y<<" "<<b<<endl;

	cout<<max(0ll,-1ll*y)+max(0ll,-1ll*b)<<endl;

  	return 0;

}