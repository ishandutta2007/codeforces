#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
mt19937_64 rng(time(0));
 
const int mn = 1e6+10;
const ll mod = 1e9+7;

ll bit[mn];
void upd(int a,ll b){for(++a;a<mn;a+=a&-a)bit[a]+=b;}
ll qu(int a){ll b=0;for(++a;a;a-=a&-a)b+=bit[a];return b;}

struct event{
	bool ins;
	int x,y;
	int e;
};

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	ll ans=1;
	vector<event>ev;
	for(int i=0;i<n;i++){
		int y,l,r;
		cin>>y>>l>>r;
		if(l==0&&r==1000000)++ans;
		ev.push_back({1,l,y,1});
		ev.push_back({1,r+1,y,-1});
	}
	for(int i=0;i<m;i++){
		int x,l,r;
		cin>>x>>l>>r;
		if(l==0&&r==1000000)++ans;
		ev.push_back({0,x,r,1});
		ev.push_back({0,x,max(0,l-1),-1});
	}
	sort(ev.begin(),ev.end(),[](auto &a, auto &b){
		if(a.x!=b.x)return a.x<b.x;
		else return a.ins>b.ins;
	});
	for(event &e:ev){
		if(e.ins){
			upd(e.y,e.e);
		}
		else{
			ans+=e.e*qu(e.y);
		}
	}
	printf("%lld\n",ans);
}