#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<x.F<<" , "<<x.S<<"}"<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define all(v) v.begin(),v.end()
#define bit(n,k) (((n)>>(k))&1)
#define Add(x,y) x=(x+y)%mod
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define int ll

const int N=2e5+99,inf=1e10;

int n,q,a[N],b[N],c[N],d[N];

struct node{
	int dist[2][2];
	node(){
		f(i,0,2) f(j,0,2) dist[i][j]=inf;
	}
	node friend operator + (node A,node B){
		node ans;
		f(i,0,2){
			f(j,0,2){
				f(k,0,2){
					minm(ans.dist[i][k],A.dist[i][j]+B.dist[j][k]);
				}
			}
		}
		return ans;
	}
} ans,def,seg[N<<2];

int dist(pair<int,int> a,pair<int,int> b){
	return abs(a.F-b.F)+abs(a.S-b.S);
}
void build(int id=1,int l=1,int r=n-1){
	if(l+1==r){
		vector<pair<int,int>> s,t;
		s.pb({a[l]+1,b[l]});
		s.pb({c[l],d[l]+1});
		t.pb({a[r],b[r]});
		t.pb({c[r],d[r]});
		f(i,0,2) f(j,0,2){
			seg[id].dist[i][j]=dist(s[i],t[j])+1;
		}
		return ;
	}
	int mid=(l+r)>>1;
	build(id<<1,l,mid);
	build(id<<1|1,mid,r);
	seg[id]=seg[id<<1]+seg[id<<1|1];
}
void get(int L,int R,int id=1,int l=1,int r=n-1){
	if(r<=L || R<=l) return ;
	if(L<=l && r<=R){
		if(ans.dist[0][0]==inf) ans=seg[id];
		else ans=ans+seg[id];
		return ;
	}
	int mid=(l+r)>>1;
	get(L,R,id<<1,l,mid);
	get(L,R,id<<1|1,mid,r);
}
int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n;
	f(i,1,n){
		cin>>a[i]>>b[i]>>c[i]>>d[i];
	}
	if(n!=2) build();
	int q;
	cin>>q;
	while(q--){
		int sx,sy,tx,ty;
		cin>>sx>>sy>>tx>>ty;
		if(max(sx,sy)==max(tx,ty)){
			cout<<dist(mp(sx,sy),mp(tx,ty))<<'\n';
			continue ;
		}
		if(max(sx,sy)>max(tx,ty)) swap(sx,tx),swap(sy,ty);
		ans=def;
		int l=max(sx,sy),r=max(tx,ty);
		//cout<<l<<" -> "<<r<<endl;
		if(l+1==r){
			ans.dist[0][0]=0;
			ans.dist[1][1]=0;		
		}
		else{
			get(l,r-1);
		}
		vector<pair<int,int>> s,t;
		s.pb({a[l],b[l]});
		s.pb({c[l],d[l]});
		t.pb({a[r-1]+1,b[r-1]});
		t.pb({c[r-1],d[r-1]+1});
		int res=inf;
		f(i,0,2) f(j,0,2){
			minm(res,ans.dist[i][j]+dist(mp(sx,sy),s[i])+dist(mp(tx,ty),t[j])+1);
		}
		cout<<res<<'\n';
	}
}
/*
4
1 1 1 1
2 1 2 2
3 2 1 3
1
2 2 4 4
*/