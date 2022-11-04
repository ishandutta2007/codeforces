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
#define int ll

int x,y;
int cnt(int m){
	int up=min((x-m)/m,y);
	int low=m+1;
	return max(0ll,up-low+1);
}

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		cin>>x>>y;
		int res=0;
		for(int i=1;i<=y;++i){
			int c=cnt(i);
			if(!c)break;
			res+=c;
		}
		cout<<res<<endl;
	}
}