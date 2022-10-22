#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=5e5+99,M=4e6,inf=1e9;

int n,t,m,tc,mv,a[N],seg[M],lazy1[M],lazy2[M];
vector<ll> b;
map<ll,int> T;
ll now;

void clear(){
	b.clear();
	T.clear();
	f(i,0,m*4+9) seg[i]=0;
	fill(lazy1,lazy1+m*4+9,0);
	fill(lazy2,lazy2+m*4+9,inf);
	now=m=0;
}
void read(){
	cin>>n;
	b.pb(0);
	f(i,1,n+1){
		int type=((i&1) ? 1 : -1);
		cin>>a[i];
		a[i]-=2;
		b.pb(now+type*a[i]);
		if(a[i]%2==0) b.pb(now+type*a[i]/2);
		now+=type*a[i];
	}
	sort(b.begin(),b.end());
	f(i,0,b.size()){
		if(i==0 || b[i]!=b[i-1]){
			T[b[i]]=++m;
		}
	}
}
void shift(int id){
	if(lazy1[id]){
		seg[id*2+0]=lazy2[id];
		seg[id*2+1]=lazy2[id];
		lazy1[id*2+0]=1;
		lazy1[id*2+1]=1;
		lazy2[id*2+0]=lazy2[id];
		lazy2[id*2+1]=lazy2[id];
	}
	else{
		minm(seg[id*2+0],lazy2[id]);
		minm(seg[id*2+1],lazy2[id]);
		minm(lazy2[id*2+0],lazy2[id]);
		minm(lazy2[id*2+1],lazy2[id]);
	}
	lazy1[id]=0;
	lazy2[id]=inf;
}
void mnk(int id,int x,int l,int r){
	if(r<=x || x<l) return ;
	if(l+1==r){
		seg[id]--;
		return ;
	}
	int mid=(l+r)/2;
	shift(id);
	mnk(id*2+0,x,l,mid);
	mnk(id*2+1,x,mid,r);
	seg[id]=min(seg[id*2+0],seg[id*2+1]);
}
void query(int id,int L,int R,int l,int r,int val){
	if(r<=L || R<=l || L==R) return ;
	if(L<=l && r<=R){
		if(val==inf){
			seg[id]=inf;
			lazy1[id]=1;
			lazy2[id]=inf;
		}
		else{
			minm(seg[id],val);
			minm(lazy2[id],val);
		}
		return ;
	}
	int mid=(l+r)/2;
	shift(id);
	query(id*2+0,L,R,l,mid,val);
	query(id*2+1,L,R,mid,r,val);
	seg[id]=min(seg[id*2+0],seg[id*2+1]);
}
void do_it(){
	now=0;
	f(i,1,n+1){
		int type=((i&1) ? 1 : -1),l=T[now],r=T[now+type*a[i]],mn=seg[1];
		if(l>r) swap(l,r);
		if(a[i]%2==0){
			int mid=T[now+type*(a[i]/2)];
			mnk(1,mid,1,m+1);
			query(1,mid,mid+1,1,m+1,mn);
		}
		query(1,l,r+1,1,m+1,mn+1);
		query(1,1,l,1,m+1,inf);
		query(1,r+1,m+1,1,m+1,inf);
		now+=type*a[i];
	}
	cout<<seg[1]+n+1<<endl;
}

main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	fill(lazy1,lazy1+M,0);
	fill(lazy2,lazy2+M,inf);
	cin>>t;
	while(t--){
		tc++;
		read();
		do_it();
		clear();
	}
}
/*
1
4
3 5 3 2
*/