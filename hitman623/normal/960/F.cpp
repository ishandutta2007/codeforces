#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,m,x[100005],y[100005],c[100005],N[100005];
vi t[100005],v[100005];
void modify(int p,int val,int h){
    for(t[h][p+=N[h]]=val;p>1;p>>=1) t[h][p>>1]=max(t[h][p],t[h][p^1]);
}
int query(int l,int r,int h){
	if(l>r) return 0; 
    int res=0;
    for(l+=N[h],r+=N[h]+1;l<r;l>>=1,r>>=1){
        if(l&1) res=max(res,t[h][l++]);
        if(r&1) res=max(res,t[h][--r]);
    }
    return res;
}
void solve(){
	cin>>n>>m;
	rep(i,0,m){
		cin>>x[i]>>y[i]>>c[i];
		v[y[i]].pb(c[i]);
	}
	rep(i,1,n+1){
		sort(all(v[i]));
		N[i]=sz(v[i]);
		t[i].resize(2*N[i]);
	}
	rep(i,0,m){
		int l=lower_bound(all(v[x[i]]),c[i])-v[x[i]].begin()-1;
		int h=query(0,l,x[i])+1;
		int r=lower_bound(all(v[y[i]]),c[i])-v[y[i]].begin();
		modify(r,h,y[i]);
	}
	int ans=0;
	rep(i,1,n+1){
		ans=max(ans,query(0,N[i]-1,i));
	}
	cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}