#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=1010;
int b[N];

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tt;cin>>tt;
	while(tt--){
		int n;cin>>n;
		for(int i=0;i<n;++i)cin>>b[i];
		sort(b,b+n);
		if(unique(b,b+n)-b==n)cout<<"NO\n";
		else cout<<"YES\n";
	}
}