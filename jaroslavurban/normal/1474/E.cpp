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

vector<pair<int,int>>ops;

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int n;cin>>n;
		vector<int>vals(n);
		if(n==2){
			cout<<"1\n2 1\n1\n2 1\n";
			continue;
		}
		if(n==3){
			cout<<"5\n2 3 1\n2\n1 3\n3 2\n";
			continue;
		}
		iota(vals.begin(),vals.end(),2);
		vals[n-1]=2;
		vals[n/2-1]=1;
		vals[0]=n/2+1;
		ll spends=0;
		for(ll i=0;i<n-1;++i)spends+=max(i*i,(n-i-1)*(n-i-1));
		cout<<spends<<endl;
		for(auto r:vals)cout<<r<<" ";cout<<endl;
		cout<<n-1<<endl;
		for(int i=1;i<n/2;++i){
			cout<<i+1<<" "<<n<<endl;
		}
		for(int i=n/2;i<n;++i){
			cout<<i+1<<" "<<1<<endl;
		}
	}
}