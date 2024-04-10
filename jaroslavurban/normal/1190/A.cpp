#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=101000;
ll n,m,k;
ll a[N];
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=0;i<m;++i)cin>>a[i];
	ll curp=a[0]/k+!!(a[0]%k);
	ll b=0,res=0;
	ll lasti=0;
	for(int i=0;i<m;++i)
		if((a[i]-b)/k+!!((a[i]-b)%k)==curp)continue;
		else{
			++res;
			b+=i-lasti;
			lasti=i;
			curp=(a[i]-b)/k+!!((a[i]-b)%k);
//			cerr<<curp<<" "<<b<<endl;
		}
	cout<<res+1<<endl;
}