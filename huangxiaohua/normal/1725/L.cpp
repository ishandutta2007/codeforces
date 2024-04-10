#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i,j,k,n,m,t,a[1005000],mx,res,f[1005000];
vector<pair<ll,ll> >v;
void add(ll x){for(;x<=n;x+=(-x&x)){f[x]++;}}
ll get(ll x,ll y=0){for(;x;x-=(-x&x)){y+=f[x];}return y;}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
		a[i]+=a[i-1];
		if(a[i]<0){cout<<-1;return 0;}
		mx=max(mx,a[i]);
	}
	if(a[n]<mx){cout<<-1;return 0;}
	for(i=1;i<n;i++)v.push_back({-a[i],-i});
	if(n>1)sort(v.begin(),v.end());
	for(auto [x,y]:v){res+=get(-y);add(-y);} 
	cout<<res;
}