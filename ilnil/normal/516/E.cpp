#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
#define fi first
#define se second
#define inf (1e18+5)
using namespace std;
const int N=1e5+5;
int n[2],iv[2],x,y,gc;
vector<int>a[N][2];
map<int,ll>g;
ll ans;
int exgcd(int a,int b,int &x,int &y){
	if(b==0)return x=1,y=0,a;
	int gc=exgcd(b,a%b,y,x);y-=x*(a/b);
	return gc;
}
void up(int x,ll v){
	if(g.count(x))g[x]=min(g[x],v);else g[x]=v;
}
ll work(vector<int>*f){
	if(f[0].size()==n[0]&&f[1].size()==n[1])return -inf;
	ll ans=0;
	fo(o,0,1){
		g.clear();
		for(int j:f[!o]){
			int x=(ll)j*iv[o]%n[o];
			up(x,j*gc);
			up((x-1+n[o])%n[o],inf);
		}
		for(int j:f[o]){
			int x=(ll)j*iv[o]%n[o];
			up((x+1)%n[o],n[!o]*gc+j*gc);
			up((x-1+n[o])%n[o],inf);
		}
		for(int j:f[o])g.erase((ll)j*iv[o]%n[o]);
		if(g.size()){
			ll la=inf;int w=0;
			for(auto &i:g)la=i.se=min(i.se,la+(ll)(i.fi-w+n[o])%n[o]*n[!o]*gc),w=i.fi;
			for(auto &i:g)la=i.se=min(i.se,la+(ll)(i.fi-w+n[o])%n[o]*n[!o]*gc),w=i.fi,ans=max(ans,i.se);
		}
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n[0]>>n[1];
	gc=exgcd(n[0],n[1],x,y);
	n[0]/=gc;n[1]/=gc;
	if(gc>1e5)return puts("-1"),0;
	iv[0]=(y%n[0]+n[0])%n[0];
	iv[1]=(x%n[1]+n[1])%n[1];
	fo(o,0,1){
		cin>>y;
		fo(i,1,y)cin>>x,a[x%gc][o].push_back(x/gc);
	}
	fo(i,0,gc-1)if(!(a[i][0].size()+a[i][1].size()))return puts("-1"),0;
	fo(i,0,gc-1)ans=max(ans,work(a[i])+i);
	cout<<ans;
}