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
		int p,f;cin>>p>>f;
		int sc,wc;cin>>sc>>wc;
		int s,w;cin>>s>>w;
		if(s>w){
			swap(s,w);
			swap(sc,wc);
		}
		int res=0;
		for(int i=0;i<=sc&&p>=i*s;++i){
			int r=i;
			int tmpsc=sc-i;
			int tmpp=p-i*s;
			int af=min(tmpsc,f/s);
			int tmpf=f-af*s;
			r+=af;
			int bp=min(wc,tmpp/w);
			r+=bp;
			int tmpwc=wc-bp;
			int bf=min(tmpwc,tmpf/w);
			r+=bf;
			res=max(res,r);
		}
		cout<<res<<endl;
	}
}