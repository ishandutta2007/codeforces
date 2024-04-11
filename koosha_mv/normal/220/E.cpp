#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define Add(x,y) x=(x+y)%mod;
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

const int N=1e5+99;

int n,k,res,ans,a[N],b[N],c[N],fen[N],fen1[N];

void add(int x, int val) { for(x++;x<N;x+=x&-x) fen[x]+=val; }
int get(int x) { int res=0; for (x++;x>0;x-=x&-x) res+=fen[x]; return res; }

void add1(int x, int val) { for(x++;x<N;x+=x&-x) fen1[x]+=val; }
int get1(int x) { int res=0; for (x++;x>0;x-=x&-x) res+=fen1[x]; return res; }

void read(){
	vector<int> cmp;
	cin>>n>>k;
	f(i,1,n+1){
		cin>>a[i];
		cmp.pb(a[i]);
	}
	sort(cmp.begin(),cmp.end());
	f(i,1,n+1){
		a[i]=lower_bound(cmp.begin(),cmp.end(),a[i])-cmp.begin();
	}
	f(i,1,n+1){
		add(a[i],1);
		b[i]=b[i-1]+(i-get(a[i]));
	}
	fill(fen,fen+N,0);
	f_(i,n,1){
		c[i]=c[i+1]+get(a[i]-1);
		add(a[i],1);	
	}	
}
void solve(){
	int l=0,r=1;
	for(;r<=n;add(a[r],-1),r++){
		while(l<r && res+b[l]+c[r]<=k){
			l++;
			add1(a[l],1);
			res+=get(a[l]-1);
		}
		ans+=max(0ll,l-1);
		res-=l-get1(a[r]);
	}
	cout<<ans;
}

main(){
	read();
	solve();
}