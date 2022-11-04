#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
//#define int ll
//#define endl '\n'

// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// print number in binary -> cout << bitset<20>(n);

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		string s;cin>>s;
		int n=s.size();
		int l1=-1,l2=-1,l3=-1;
		int res=n+1;
		for(int i=0;i<n;++i){
			if(s[i]=='1')l1=i;
			if(s[i]=='2')l2=i;
			if(s[i]=='3')l3=i;
			if(~min({l1,l2,l3}))
				res=min(res,1+i-min({l1,l2,l3}));
		}
		if(res==n+1)cout<<0<<endl;
		else cout<<res<<endl;
	}
}