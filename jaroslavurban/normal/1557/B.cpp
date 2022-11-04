#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#include <bits/extc++.h>
__gnu_pbds::gp_hash_table<int,int>real2fake;
vector<int>fake2real;

// not tested
// other == inits real2fake
void compress(vector<int>&a,bool other=false){
	int n=a.size();
	vector<pair<int,int>>vals(n);
	for(int i=0;i<n;++i)vals[i]={a[i],i};
	sort(vals.begin(),vals.end());
	int pri=-1,prv=-1;
	for(auto[v,i]:vals){
		if(v!=prv){
			prv=v,++pri;
			fake2real.push_back(v);
			if(other)real2fake[v]=pri;
		}
		a[i]=pri;
	}
}

void ProGamerMove(){
	int n,k;cin>>n>>k;
	vector<int>a(n);
	for(auto&v:a)cin>>v;
	compress(a);
	int cnt=0;
	for(int i=1;i<n;++i)if(a[i-1]+1!=a[i])++cnt;
	if(cnt+1<=k)cout<<"Yes\n";
	else cout<<"No\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout<<setprecision(9)<<fixed;
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}