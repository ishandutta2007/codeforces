#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int N=200100;
ll p[N];
ll n,x,a,y,b,k;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

bool possible(ll m){
	ll got=0;
	ll cntboth=m/lcm(a,b),cnb=m/lcm(a,b);
	int i=0;
	for(;i<m&&cntboth--;++i)got+=p[i]/100*(x+y);
	ll cnta=m/a-cnb;
	for(;i<m&&cnta--;++i)got+=p[i]/100*x;
	ll cntb=m/b-cnb;
	for(;i<m&&cntb--;++i)got+=p[i]/100*y;
	return got>=k;
}


main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tt;cin>>tt;
	while(tt--){
		cin>>n;
		for(int i=0;i<n;++i)cin>>p[i];
		sort(p,p+n);
		reverse(p,p+n);
		cin>>x>>a>>y>>b>>k;
		if(x<y){swap(a,b);swap(x,y);}
		int l=0,r=n+1;
		while(l<r){
			int m=(l+r)/2;
			if(possible(m))r=m;
			else l=m+1;
		}
		if(l==n+1)cout<<-1<<endl;
		else cout<<l<<endl;
	}
}