#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
const lll ONE=1;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=3e5+10;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
ll ninv[30][2];
void hail(vector<ll>v,int b){
	if(!v.size())return;
	vector<int>sp;
	for(ll x:v)sp.push_back((x>>b)&1);
	ll n1=0;
	for(int x:sp){
		if(x)n1++;
		else ninv[b][0]+=n1;
	}
	n1=0;
	for(int x:sp){
		if(!x)n1++;
		else ninv[b][1]+=n1;
	}
	//cerr<<endl;
	if(!b)return;
	vector<ll>a,aa;
	for(ll x:v){
		if((x>>b)&1)a.push_back(x);
		else aa.push_back(x);
	}
	hail(a,b-1),hail(aa,b-1);
}
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#endif
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin>>n;
    vector<ll>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    hail(v,29);
	ll ans=0,av=0;
	for(int i=29;i>=0;i--){
		//cerr<<ninv[i][0]<<' '<<ninv[i][1]<<endl;
		if(ninv[i][1]<ninv[i][0])ans+=(1LL<<i),av+=ninv[i][1];
		else av+=ninv[i][0];
	}
	printf("%lld %lld",av,ans);
}