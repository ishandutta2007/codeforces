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

const int N=110;
ll h[N];

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int n;cin>>n;
		for(int i=0;i<n;++i)cin>>h[i];
		ll got=0;
		int ch=-1;
		bool pos=true;
		for(int i=0;i<n;++i){
			if(got+h[i]<=ch)pos=false;
			if(h[i]>ch)got+=h[i]-(ch+1);
			else got-=(ch+1)-h[i];
			++ch;
		}
		if(pos)cout<<"YES\n";
		else cout<<"NO\n";
	}
}