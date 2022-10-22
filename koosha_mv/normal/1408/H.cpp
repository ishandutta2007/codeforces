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

const int N=5e5+99;

int n,t,a[N],b[N],seg[N<<2],lz[N<<2];
vector<int> L0,R0,P[N],vec[N];

void shift(int id){
  seg[id*2+0]+=lz[id];
  seg[id*2+1]+=lz[id];
  lz[id*2+0]+=lz[id];
  lz[id*2+1]+=lz[id];
  lz[id]=0;
}
void build(int id=1,int l=1,int r=n+1){
	if(l+1==r){
		seg[id]=n+1-l;
		return ;
	}
	int mid=(l+r)/2;
	build(id*2+0,l,mid);
	build(id*2+1,mid,r);
	seg[id]=max(seg[id*2+0],seg[id*2+1]);
}
void add(int L,int R,int val,int id=1, int l=1,int r=n+1){
  if(r<=L || R<=l) return ;
  if(L<=l && r<=R){
    lz[id]+=val;
    seg[id]+=val;
    return ;   
  }
  int mid=(l+r)>>1;
  shift(id);
  add(L,R,val,id*2+0,l,mid);
  add(L,R,val,id*2+1,mid,r);
  seg[id]=max(seg[id*2+0],seg[id*2+1]);
}
int MaxF(){
	build();
	int ans=0;
	f(i,1,n+1) P[a[i]].pb(b[i]);
	f(i,0,n+1){
		maxm(ans,seg[1]+n+1-i);
		for(auto x : P[i]){
			add(x+1,n+1,1);
		}
	}
	return ans;
}
void Main(){
	cin>>n;
	f(i,1,n+1){
		cin>>a[i];
		vec[a[i]].pb(i);
	}
	f(i,0,vec[0].size()/2) L0.pb(vec[0][i]),R0.pb(vec[0][vec[0].size()-i-1]);
	reverse(all(R0));
	//dbgv(L0);
	//dbgv(R0);
	if(L0.size()==0){
		cout<<0<<'\n';
		return ;
	}
	f(i,1,n+1){
		a[i]=0,b[i]=0;
		for(auto x : vec[i]){
			if(x<R0[0]){
				maxm(a[i],int(lower_bound(all(L0),x)-L0.begin()));
			}
			if(L0.back()<x){
				maxm(b[i],int(R0.end()-lower_bound(all(R0),x)));
			}
		}
		//cout<<a[i]<<" "<<b[i]<<endl;
	}
	cout<<min(3*n-MaxF(),int(L0.size()))<<'\n';
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		Main();
		L0.clear();
		R0.clear();
		f(i,0,n+1) vec[i].clear(),P[i].clear();
		f(i,0,(n<<2)+10) seg[i]=lz[i]=0;
	}
}