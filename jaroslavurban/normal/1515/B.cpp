#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int solve(int n){
	int sq1=sqrt(n/4);
	int sq2=sqrt(n/2);
	if(sq1*sq1*4==n||sq2*sq2*2==n)cout<<"YES\n";
	else cout<<"NO\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int n;cin>>n;
		solve(n);
	}
}