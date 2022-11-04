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
		int n,k;cin>>n>>k;
		string s;cin>>s;
		int last=-k-1;
		int res=0;
		for(int i=0;i<n;++i)
			if(s[i]=='1'){
				//cerr<<i-last-1<<endl;
				res+=max(0,(i-last-1)/(k+1)-((i-last-1)%(k+1)<k));
				last=i;
			}
		if(~last)++last;
		//cerr<<res<<" "<<(n+k-last)<<endl;
		//cerr<<(n+k-last)%(k+1)<<endl;
		res+=max(0,(n+k-last)/(k+1)-((n+k-last)%(k+1)<k));
		cout<<res<<endl;
	}
}