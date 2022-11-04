#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100100;
int a[N];

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int n,q;cin>>n>>q;
	for(int i=0;i<n;++i)cin>>a[i];
	int ones=accumulate(a,a+n,0);
	while(q--){
		int t,k;cin>>t>>k;--k;
		if(t==1){
			if(a[k]==1)--ones;
			else ++ones;
			a[k]=!a[k];
		}
		if(t==2){
			if(ones>=k+1)cout<<1<<endl;
			else cout<<0<<endl;
		}
	}
}