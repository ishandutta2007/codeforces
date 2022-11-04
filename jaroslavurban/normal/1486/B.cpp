#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// bool xd=any_of(a.begin(),a.end(),[&](int x){return x==9;});
// all_of, none_of
// int cnt=count(a.begin(),a.end(),x);
// bool found=binary_search(a.begin(),a.end(),x); true if x in sorted array
// int xd=*max_element(a.begin(),a.end());
// min_element

typedef long long ll;
typedef long double ld;

const int N=1010;
ll x[N],y[N];

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int n;cin>>n;
		for(int i=0;i<n;++i)cin>>x[i]>>y[i];
		if(n&1)cout<<1<<endl;
		else{
			sort(x,x+n);
			sort(y,y+n);
			cout<<(x[n/2]-x[n/2-1]+1)*(y[n/2]-y[n/2-1]+1)<<endl;
		}
	}
}