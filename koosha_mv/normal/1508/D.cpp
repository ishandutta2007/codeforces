#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=2005;
 
int n,x,p[N],par[N];
pair<int,int> mn=mp(N*N,N*N),a[N];
vector<int> v;
vector<pair<int,int> > ans;

pair<int,int> shib(pair<int,int> a,pair<int,int> b){
	b.F-=a.F;
	b.S-=a.S;
	swap(b.F,b.S);
	return b;
}
bool mog(pair<int,int> a,pair<int,int> b){
	if(a.S==0) return 0;
	if(b.S==0) return 1;
	return 1ll*a.F*b.S<1ll*a.S*b.F;
}
bool cmp(int i,int j){
	return mog(shib(a[x],a[i]),shib(a[x],a[j]));
}
int Get_par(int u){
	if(par[u]<0) return u;
	return par[u]=Get_par(par[u]);
}
void merge(int u,int v){
	swap(p[u],p[v]);
	ans.pb(mp(u,v));
	u=Get_par(u),v=Get_par(v);
	if(par[u]>par[v]) swap(u,v);	
	par[u]+=par[v];
	par[v]=u;
}

int main(){
	cin>>n;
	f(i,1,n+1){
		cin>>a[i].F>>a[i].S>>p[i];
	}
	f(i,1,n+1){
		if(!par[i] && p[i]!=i){
			v.pb(i);
			par[i]=-1;
			for(int u=p[i];u!=i;u=p[u]){
				v.pb(u);
				par[i]--;
				par[u]=i;
			}
		}
	}
	if(v.size()==0) return cout<<0,0;
	f(i,0,v.size()){
		if(a[v[i]]<mn)
			mn=a[v[i]],x=v[i];
	}
	f(i,0,v.size()){
		if(v[i]==x){
			v.erase(v.begin()+i);
			break;
		}
	}
	sort(v.begin(),v.end(),cmp);
	f(i,0,v.size()-1){
		if(Get_par(v[i])!=Get_par(v[i+1]))
			merge(v[i],v[i+1]);
	}
	while(p[x]!=x){
		ans.pb(mp(x,p[x]));
		swap(p[x],p[p[x]]);
	}
	cout<<ans.size()<<endl;
	f(i,0,ans.size())
		cout<<ans[i].F<<" "<<ans[i].S<<endl;
}