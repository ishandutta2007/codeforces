#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
const lll mod=(1LL<<61)-1;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const lll mul=57497633;
const int mn=2e5+10;

ll a[mn];
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>a[i];
    string s;
	cin>>s;
	vector<ll>v;
	ll ans=0;
	for(int i=0;i<n;i++){
		if(i&&s[i]!=s[i-1]){
			sort(v.begin(),v.end(),greater<ll>());
			for(int j=0;j<min(k,(int)v.size());j++)ans+=v[j];
			v.clear();
		}
		v.push_back(a[i]);
	}
	sort(v.begin(),v.end(),greater<ll>());
	for(int j=0;j<min(k,(int)v.size());j++)ans+=v[j];
	printf("%lld",ans);
}