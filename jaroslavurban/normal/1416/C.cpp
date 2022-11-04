#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=300300;
ll flipped[40],notflipped[40];

void cntflips(vector<ll>a,int idx){
	if(idx<0||a.empty())return;
//	cerr<<a.size()<<" "<<idx<<endl;
	const int n=a.size();
	ll ones=0,zeros=0;
	ll fl=0,nfl=0;
	vector<ll>o,z;
	for(int i=n-1;i>=0;--i)
		if(a[i]&(1ll<<idx)){
			++ones;
			nfl+=zeros;
			o.push_back(a[i]);
		}else{
			++zeros;
			fl+=ones;
			z.push_back(a[i]);
		}
	reverse(o.begin(),o.end());
	reverse(z.begin(),z.end());
	flipped[idx]+=fl;
	notflipped[idx]+=nfl;
	cntflips(o,idx-1);
	cntflips(z,idx-1);
}


main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int n;cin>>n;
	vector<ll>a(n);
	for(int i=0;i<n;++i)cin>>a[i];
	cntflips(a,32);
	ll x=0,res=0;
	for(ll i=0;i<32;++i)if(notflipped[i]<=flipped[i]){
		res+=notflipped[i];
	}
	else{
		res+=flipped[i];
		x|=(1ll<<i);
	}
	cout<<res<<" "<<x<<endl;
}