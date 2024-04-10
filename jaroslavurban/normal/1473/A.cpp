#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

main(){
	cin.tie(0);ios_base::sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int n,d;cin>>n>>d;
		vector<int>a(n);
		for(int i=0;i<n;++i)cin>>a[i];
		sort(a.begin(),a.end());
		if(a[0]+a[1]<=d||a.back()<=d)cout<<"YES\n";
		else cout<<"NO\n";
	}
}