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

const int N=1e5+99,inf=1e9+7,lg=30;

int n,q,a[N],Fen[N],seg[N<<1],ans[N<<2];
vector<int> vec;
vector<pair<int,int>> Q[N];

void add(int x, int val){ for (x++;x>0;x-=x&-x) minm(Fen[x],val); }
int get(int x) { int res=inf; for(x++;x<N;x+=x&-x) minm(res,Fen[x]); return res; }

int get_seg(int l,int r){
	int res=0;
	for(l+=n,r+=n;l<r;l>>=1,r>>=1){
		if(l&1) maxm(res,seg[l++]);
		if(r&1) maxm(res,seg[--r]);
	}
	return res;
}
int get(int l,int r){
	l=lower_bound(all(vec),l)-vec.begin();
	r=lower_bound(all(vec),r)-vec.begin();
	return get_seg(l,r);
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	fill(Fen,Fen+N,inf);
	cin>>n;
	f(i,1,n+1){
		cin>>a[i];
		vec.pb(a[i]);
	}
	sort(all(vec));
	cin>>q;
	f(i,0,q){
		int l,r;
		cin>>l>>r;
		Q[r].pb({l,i});
	}
	f(i,1,n+1){
		add(get(a[i],a[i]+1),0);
		f(l,0,lg){
			int pos=get(a[i]+(1<<l),a[i]+(1<<(l+1)));
			add(pos,a[pos]-a[i]);
		}
		f(l,0,lg){
			int pos=get(a[i]-(1<<(l+1))+1,a[i]-(1<<l)+1);
			add(pos,a[i]-a[pos]);
		}
		for(auto p : Q[i]){
			ans[p.S]=get(p.F);
		}
		for(int id=lower_bound(all(vec),a[i])-vec.begin()+n;id;id>>=1) seg[id]=i;
	}
	f(i,0,q){
		cout<<ans[i]<<" ";
	}
}