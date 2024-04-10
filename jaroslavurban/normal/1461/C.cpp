#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100100;
int a[N],r[N];
ld p[N];
int n,m;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		cin>>n>>m;
		for(int i=0;i<n;++i)cin>>a[i];
		for(int i=0;i<m;++i)cin>>r[i]>>p[i];
		int sort=n;
		for(int i=n-1;i>=0;--i)if(a[i]==i+1)--sort;
		else break;
		if(!sort){cout<<1<<endl;continue;}
		ld nots=1;
		for(int i=0;i<m;++i)if(r[i]>=sort)nots*=(1-p[i]);
		cout<<setprecision(8)<<fixed<<1-nots<<endl;
	}
}