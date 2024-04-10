#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-9;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
const int mn=3e5+10;

ll seg[mn*4],laz[mn*4];
void prop(int x){
	if(!laz[x])return;
	seg[x]+=laz[x];
	if(x*2+1<mn*4){
		laz[x*2]+=laz[x];
		laz[x*2+1]+=laz[x];
	}
	laz[x]=0;
}
void eval(int x){
	prop(x*2),prop(x*2+1);
	seg[x]=max(seg[x*2],seg[x*2+1]);
}
#define mid ((l+r)>>1)
void upd(int x,int l,int r,int a,int b,ll c){
	if(l==a&&r==b)laz[x]+=c;
	else{
		prop(x);
		if(b<=mid)upd(x*2,l,mid,a,b,c);
		else if(a>mid)upd(x*2+1,mid+1,r,a,b,c);
		else upd(x*2,l,mid,a,mid,c),upd(x*2+1,mid+1,r,mid+1,b,c);
		eval(x);
	}
}
ll query(int x,int l,int r,int a,int b){
	prop(x);
	if(l==a&&r==b)return seg[x];
	else if(b<=mid)return query(x*2,l,mid,a,b);
	else if(a>mid)return query(x*2+1,mid+1,r,a,b);
	else return max(query(x*2,l,mid,a,mid),query(x*2+1,mid+1,r,mid+1,b));
}
ll h[mn],b[mn],dp[mn];
void hailveshy(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>h[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	stack<int> st;
	st.push(0);
	dp[0]+=b[1];
	upd(1,0,n,0,0,dp[0]);
	//cerr<<query(1,0,n,0,0);
	for(int i=1;i<=n;i++){
		while(h[i]<h[st.top()]){
			int x=st.top();
			st.pop();
			int y=st.top();
			upd(1,0,n,y,x-1,b[i]-b[x]);
		}
		st.push(i);
		dp[i]=query(1,0,n,0,i-1);
		if(i==n)break;
		dp[i]+=b[i+1];
		upd(1,0,n,i,i,dp[i]);
	}
	
	printf("%lld\n",dp[n]);
}

int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	int tc=1;
	//cin>>tc;
	for(int tcc=1;tcc<=tc;tcc++){
		hailveshy();
	}
}