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
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=4e6+99;
 
int n,m,p,t,cnt,a[N],b[N],c[N];
vector<int> v[N];
map<int,int> T;
ll ans;
 
int Fen[N];
void update(int x,int val) { while(x<=n+m)  {  Fen[x]+=val;  x+=(x&-x);  } }
int query(int x) {  int res=0;  while(x>0)  {  res+=Fen[x];  x-=(x&-x);  } return res; } 
 
void Add(int x){
	ans+=query(n+m)-query(x);
	update(x,1);
}
void make(){
	cnt=1;
	sort(c,c+n+m);
	f(i,0,n+m){
		if(i==0 || c[i]!=c[i-1]){
			T[c[i]]=cnt++;
		}
	}
	f(i,1,n+1) a[i]=T[a[i]];
	f(i,1,m+1) b[i]=T[b[i]];
	sort(b+1,b+1+m);
	f(i,1,n+1){
		if(a[i]>n+m)
			eror(99);
	}
	f(i,1,m+1){
		if(b[i]>n+m)
			eror(90);
	}
}
void solve(int L,int R,int l,int r){
	if(R<=L) return;
	int Mid=(L+R)/2,x=b[Mid],ans=0,mn=N,mid=0;
	f(i,l,r){
		if(a[i]<x) ans--;
		if(a[i]>x) ans++;
		if(ans<mn){
			mn=ans,mid=i;
		}
	}
	v[mid].pb(x);
	solve(L,Mid,l,mid+1);
	solve(Mid+1,R,mid,r);
}
 
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		ans=p=0;
		cin>>n>>m;
		f(i,1,n+1){
			cin>>a[i];
			c[i-1]=a[i];
		}
		f(i,1,m+1){
			cin>>b[i];
			c[n+i-1]=b[i];
		}
		make();
		solve(1,m+1,0,n+1);
		f(i,0,n+1){
			if(i) Add(a[i]);
			sort(v[i].begin(),v[i].end());
			f(j,0,v[i].size()){
				Add(v[i][j]);
			}
			v[i].clear();
		}
		cout<<ans<<endl;
		T.clear();
		fill(Fen,Fen+n+m+9,0);
	}
}