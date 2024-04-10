#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=5e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
ll da[mn],db[mn];
int main(){
	#ifdef LOCAL_PROJECT
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#else
	cin.tie(0);
	cin.sync_with_stdio(0);
	#endif
	int n,d,m;
	cin>>n>>d>>m;
	vector<ll>s,l;
	for(int i=0;i<n;i++){
		ll x;
		cin>>x;
		if(x>m)l.push_back(x);
		else s.push_back(x);
	}
	sort(l.begin(),l.end(),greater<int>());
	sort(s.begin(),s.end(),greater<int>());
	for(int i=1;i<l.size();i++)l[i]+=l[i-1];
	l.insert(l.begin(),0);
	for(int i=1;i<s.size();i++)s[i]+=s[i-1];
	s.insert(s.begin(),0);
	ll ans=-inf;
	for(int i=0;i<l.size();i++){
		int j=min(n-(1+(i-1)*(d+1)),(int)s.size()-1);
		if(j<0)break;
		cerr<<s[j]+l[i]<<' ';
		ans=max(ans,s[j]+l[i]);
	}
	printf("%lld",ans);
}