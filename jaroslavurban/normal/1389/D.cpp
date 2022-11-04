#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll
//#define endl '\n'

// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// print number in binary -> cout << bitset<20>(n);


int n,k,la,lb,ra,rb;
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		cin>>n>>k>>la>>ra>>lb>>rb;
		if(la>lb){
			swap(la,lb);swap(ra,rb);
		}
		int oneint=max(min(rb,ra)-lb,0ll);
		int totalS=0;
		int totalint=oneint*n;
		if(totalint>=k){cout<<0<<endl;continue;}
		int wholeS=lb-la+abs(ra-rb),wholeI=max(ra,rb)-min(la,lb)-oneint;
		int alt=1e18;
		//cerr<<oneint<<" "<<wholeI<<" "<<wholeS<<endl;
		int used=0;
		while(used<n&&totalint+wholeI<k){totalS+=wholeS;totalint+=wholeI;++used;
			alt=min(alt,totalS+2*(k-totalint));}
		//cerr<<totalint<<" "<<totalS<<endl;
		//cerr<<used<<endl;
		if(used==n){cout<<alt<<endl;continue;}
		//cerr<<k<<" "<<totalint<<endl;
		totalS+=max(0ll,lb-ra)+k-totalint;
		cout<<min(totalS,alt)<<endl;
	}
}