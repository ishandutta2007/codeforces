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

const int N=1e6+99,inf=1e18;

int n,t,a[N],ps[N],seg[2][N],F[N];

void build(){
	f(i,0,n) seg[0][i+n]=seg[1][i+n]=ps[i];
	f_(i,n-1,1){
		seg[0][i]=min(seg[0][i<<1],seg[0][i<<1|1]);
		seg[1][i]=max(seg[1][i<<1],seg[1][i<<1|1]);
	}
}
int get(int l,int r){
	int ans=n;
	a[n]=-inf;
	for(l+=n,r+=n;l<r;l>>=1,r>>=1){
		if(l&1){
			if(a[F[l]]>a[ans]) ans=F[l];
			l++;
		}
		if(r&1){
			r--;
			if(a[F[r]]>a[ans]) ans=F[r];
		}
	}
	return ans;
}
int getmn(int l,int r){
	int ans=inf;
	for(l+=n,r+=n;l<r;l>>=1,r>>=1){
		if(l&1) minm(ans,seg[0][l++]);
		if(r&1) minm(ans,seg[0][--r]);
	}
	return ans;
}
int getmx(int l,int r){
	int ans=-inf;
	for(l+=n,r+=n;l<r;l>>=1,r>>=1){
		if(l&1) maxm(ans,seg[1][l++]);
		if(r&1) maxm(ans,seg[1][--r]);
	}
	return ans;
}
bool check(int l,int r){
	if(r<=l+1) return 1;
	int id=get(l,r);
	if(ps[id]<getmx(id+1,r)) return 0;
	if(min(getmn(max(0ll,l-1),id),l==0 ? 0 : inf)<ps[id-1]) return 0;
	return check(l,id) && check(id+1,r);
}
void Main(){
	vector<pair<int,int>> vec;
	cin>>n;
	f(i,0,n){
		cin>>a[i];
		vec.pb({a[i],i});
		ps[i]+=a[i];
		ps[i+1]+=ps[i];
	}
	sort(all(vec));
	f(i,0,vec.size()){
		int x=vec[i].S+n;
		while(x){
			F[x]=vec[i].S;
			x>>=1;
		}
	}
	build();
	if(check(0,n)) cout<<"YES"<<'\n';
	else cout<<"NO"<<'\n';
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		Main();
		f(i,0,2*n) seg[0][i]=seg[1][i]=a[i]=ps[i]=F[i]=0;
	}
}