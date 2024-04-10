#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
const lll ONE=1;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=1e6+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
int a[mn],b[mn];
struct edge{
	int a,b;
	ll c;
};
int p[mn];
int f(int x){return x==p[x]?x:(p[x]=f(p[x]));}
int main(){
	#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#endif
    cin.tie(0);
    cin.sync_with_stdio(0);
    int m,n;
    cin>>m>>n;
    for(int i=1;i<=m;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    vector<edge>v;
	ll ans=0;
    for(int i=1;i<=m;i++){
    	int k;
    	cin>>k;
    	for(int j=0;j<k;j++){
    		int x;
    		cin>>x;
    		v.push_back({i,x+m,a[i]+b[x]});
    		ans+=a[i]+b[x];
    	}
    }
    iota(p,p+mn,0);
    sort(v.begin(),v.end(),[](auto a,auto b){return a.c>b.c;});
    for(edge e:v){
    	if(f(e.a)==f(e.b))continue;
    	ans-=e.c;
    	p[f(e.a)]=f(e.b);
    }
    printf("%lld\n",ans);
}