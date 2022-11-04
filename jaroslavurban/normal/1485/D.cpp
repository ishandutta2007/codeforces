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
	int n,m;cin>>n>>m;
	for(int i=0;i<n;++i,cout<<endl)
		for(int j=0;j<m;++j){
			int x;cin>>x;
			cout<<720720+((i+j)%2?x*x*x*x:0)<<" ";
		}
}