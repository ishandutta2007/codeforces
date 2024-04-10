#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=1e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
int bit[mn];
void upd(int a,int b){for(a++;a<mn;a+=a&-a)bit[a]+=b;}
int qu(int a){int b=0;for(a++;a;a-=a&-a)b+=bit[a];return b;}
ll a[mn];
vector<int>g[mn];
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i],a[i]=abs(a[i]),g[a[i]].push_back(i);
    ll ans=0;
	for(int i=0;i<n;i++)upd(i,1);
    for(int i=mn-1;i>=0;i--){
    	for(int j:g[i]){
    		upd(j,-1);
    	}
    	for(int j:g[i]){
    		int aa=qu(j-1),bb=qu(mn-2)-qu(j);
    		ans+=min(aa,bb);
    	}
    }
    printf("%lld",ans);
}