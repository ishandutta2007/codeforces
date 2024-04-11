#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define bit(x) (1ll<<(x*1ll))
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=5e5+99,e=2e5+1;

int n,q,x,sz,mark[N],t[N],a[N];
vector<pair<int,int> > com[N];
ll ans;

void find_prime(){
	mark[1]=1;
	f(i,2,N)
		if(!mark[i])
			for(int j=i*2;j<N;j+=i)
				mark[j]=1;
}
pair<int,int> mv(vector<int> v,int mask){
	pair<int,int> res;
	res.F=1;
	f(i,0,v.size()){
		if(mask%2) res.F*=v[i],res.S=1-res.S;
		mask/=2;
	}
	return res;
}
void solve(int x,int z){
	int res=0;
	f(i,0,com[x].size()){
		if(com[x][i].S) res+=t[com[x][i].F];
		else res-=t[com[x][i].F];
	}
	res=sz-res;
	ans+=res*z;
}
void add(int x,int z){
	f(i,0,com[x].size())
		t[com[x][i].F]+=z;
}

int main(){
	find_prime();
	cin>>n>>q;
	
	f(i,0,n){
		gett(a[i]);
		vector<int> v;
		for(int j=1;j*j<=a[i];j++)
			if(a[i]%j==0){
				if(!mark[j])
					v.pb(j);
				if(j*j!=a[i] && !mark[a[i]/j])
					v.pb(a[i]/j);
			}
		f(j,1,(1<<v.size()))
			com[i].pb(mv(v,j));
	}
	
	fill(mark,mark+N,0);
	f(i,0,q){
		gett(x);
		x--;
		if(!mark[x]){
			solve(x,1);
			add(x,1);
			sz++;
			mark[x]=1;
		}
		else{
			sz--;
			add(x,-1);
			solve(x,-1);
			mark[x]=0;
		}
		cout<<ans<<'\n';
	}
}