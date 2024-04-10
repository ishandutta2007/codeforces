#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
const int mn=2e5+10;
ll dot(pll a,pll b){return a.first*b.first+a.second*b.second;}
ll cross(pll a,pll b){return a.first*b.second-a.second*b.first;}
bool ccw(pll a,pll b,pll c){return cross({b.first-a.first,b.second-a.second},{c.first-b.first,c.second-b.second})>0;}
vector<pll> cvxhull(vector<pll> p){
	int n=p.size();
	sort(p.begin(),p.end());
	vector<pll>cvx,cvx2;
	for (int i = 0; i<n; i++) {
		while(cvx.size()>=2&&!ccw(cvx[cvx.size()-2],cvx.back(),p[i]))cvx.pop_back();
		cvx.push_back(p[i]);
	}
	cvx2.push_back(cvx.back());
	for (int i = n - 2; i >= 0; i--) {
		while(cvx2.size()>=2&&!ccw(cvx2[cvx2.size()-2],cvx2.back(),p[i]))cvx2.pop_back();
		cvx2.push_back(p[i]);
	}
	for(int i=1;i+1<cvx2.size();i++)cvx.push_back(cvx2[i]);
	for(auto e:cvx)cerr<<e.first<<" "<<e.second<<"\n";
	cerr<<"\n";
	return cvx;
}
struct ele{
	ll len,cr,dt;
	bool operator==(const ele&o){return len==o.len&&cr==o.cr&&dt==o.dt;}
};
ll sq(ll x){return x*x;}
pll minu(pll a,pll b){return {a.first-b.first,a.second-b.second};}
vector<ele> getel(vector<pll>p){
	vector<ele>e;
	int n=p.size();
	for(int i=0;i<n;i++){
		e.push_back({sq(p[(i+1)%n].first-p[i].first)+sq(p[(i+1)%n].second-p[i].second),0,0});
		e.push_back({0,cross(minu(p[(i+2)%n],p[(i+1)%n]),minu(p[(i+1)%n],p[i])),dot(minu(p[(i+2)%n],p[(i+1)%n]),minu(p[(i+1)%n],p[i]))});
	}
	return e;
}
int main(){
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		freopen("error.txt","w",stderr);
	#else
		cin.tie(0);
		cin.sync_with_stdio(0);
	#endif
	vector<pll>p,q;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		ll x,y;
		cin>>x>>y;
		p.push_back({x,y});
	}
	for(int i=0;i<m;i++){
		ll x,y;
		cin>>x>>y;
		q.push_back({x,y});
	}
	p=cvxhull(p);
	q=cvxhull(q);
	if(p.size()!=q.size()){printf("NO");return 0;}
	for(auto e:p)cerr<<e.first<<" "<<e.second<<"\n";
	cerr<<"\n";
	for(auto e:q)cerr<<e.first<<" "<<e.second<<"\n";
	vector<ele>pe=getel(p),qe=getel(q);
	for(int i=0;i<qe.size();i++)pe.push_back(pe[i]);
	vector<int>lcp(qe.size());
	for(int i=1,j=0;i<qe.size();){
		if(qe[i]==qe[lcp[i]])lcp[i++]=++j;
		else if(j)j=lcp[j-1];
		else i++;
	}
	for(int i=0,j=0;i<pe.size();){
		if(j==qe.size()){printf("YES");return 0;}
		else if(pe[i]==qe[j])i++,j++;
		else if(j)j=lcp[j-1];
		else i++;
	}
	printf("NO");
}