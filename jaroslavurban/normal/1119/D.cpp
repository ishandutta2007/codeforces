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

const int N=100010;
ll a[N];
int n,q;
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;++i)cin>>a[i];
	sort(a,a+n);
	vector<ll>diffs,presm;
	for(int i=0;i<n-1;++i)
		diffs.push_back(a[i+1]-a[i]);
	sort(diffs.begin(),diffs.end());
	ll cur=n;
	ll prsm=0; // check n=1
	if(n>1)presm.push_back(prsm+=cur--*diffs[0]);
	for(int i=1;i<n-1;++i)
		presm.push_back(prsm+=cur--*(diffs[i]-diffs[i-1]));
	
	cin>>q;
	while(q--){
		ll r,l;cin>>l>>r;
		ll df=r-l+1;
		if(n==1){cout<<df<<" ";continue;}
		l=0,r=n-2;
		while(r>l){
			ll mid=(r+l+1)/2;
			if(diffs[mid]<=df)l=mid;
			else r=mid-1;
		}
//		for(int i=0;i<n-1;++i)cerr<<presm[i]<<" ";cerr<<endl;
//		cerr<<presm[l]<<endl;
//		cerr<<l<<endl;

		if(diffs[l]>df)cout<<n*df<<" ";
		else {
			ll res=presm[l];
			res+=(df-diffs[l])*(n-(l+1));
			cout<<res<<" ";
		}
	}
	cout<<endl;
}