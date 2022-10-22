#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int mn = 8e5+10;
const ll mod = 1e9+7;

ll a[mn];
vector<pll> its[mn];
vector<ll>dp1,dp2,lp,rp;


void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=0;i<=n;i++)its[i].clear();
	sort(a+1,a+n+1);
	
	for(int i=0;i<m;i++){
		int l,r;
		cin>>l>>r;
		int li=lower_bound(a+1,a+n+1,l)-a-1;
		int ri=upper_bound(a+1,a+n+1,r)-a-1;
		//cerr<<l<<" "<<r<<" "<<li<<" "<<ri<<endl;
		if(li!=ri)continue;
		its[li].push_back({l,r});
	}
	for(int i=0;i<=n;i++){
		vector<pll> t;
		sort(its[i].begin(),its[i].end(),[](auto a, auto b){
			if(a.first!=b.first)return a.first<b.first;
			return a.second>b.second;
		});
		for(pll p:its[i]){
			//cerr<<i<<" "<<p.first<<" "<<p.second<<endl;
			while(t.size()&&p.second<=t.back().second)t.pop_back();
			t.push_back(p);
		}
		its[i]=t;
	}
	for(int i=0;i<n;i++)its[i].push_back({a[i+1],a[i+1]});
	its[n].push_back({0,0});
	dp1.assign(its[0].size(),0x3f3f3f3f3f3f3f3f);
	dp1[0]=0;
	for(int i=1;i<=n;i++){
		dp2.assign(its[i].size(),0x3f3f3f3f3f3f3f3f);
		lp=rp=dp1;
		for(int j=0;j<dp1.size();j++){
			lp[j]+=(a[i]-its[i-1][j].second);
			rp[j]+=2*(a[i]-its[i-1][j].second);
		}
		for(int j=1;j<lp.size();j++)lp[j]=min(lp[j],lp[j-1]);
		for(int j=(int)rp.size()-2;j>=0;j--)rp[j]=min(rp[j],rp[j+1]);
		vector<ll> r;
		for(pll p:its[i-1])r.push_back(p.second);
		for(int j=0;j<dp2.size();j++){
			ll d=j?its[i][j-1].first-a[i]:0;
			int co=lower_bound(r.begin(),r.end(),a[i]-d)-r.begin();
			ll lv=(co>=1)?lp[co-1]+2*d:0x3f3f3f3f3f3f3f3f;
			ll rv=rp[co]+d;
			dp2[j]=min(lv,rv);
			//cerr<<i<<" "<<j<<" "<<dp2[j]<<endl;
		}
		dp1=dp2;
	}
	for(int i=0;i<=n;i++)cerr<<its[i].size()-1<<endl;
	printf("%lld\n",dp1.back());
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int tc;
	cin>>tc;
	for(int tcc=1;tcc<=tc;++tcc){
		int temp;
		solve();
	}
}