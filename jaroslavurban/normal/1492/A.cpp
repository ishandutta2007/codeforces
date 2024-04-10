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

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		unsigned long long p,a,b,c;cin>>p>>a>>b>>c;
		unsigned long long res=ULLONG_MAX;
		res=min(res,(p/a+!!(p%a))*a);
		res=min(res,(p/b+!!(p%b))*b);
		res=min(res,(p/c+!!(p%c))*c);
		cout<<res-p<<endl;
	}
}