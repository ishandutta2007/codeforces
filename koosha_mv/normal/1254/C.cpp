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

const int N=5e6+99;

int n,t,a[N];
vector<int> ans;
vector<pair<int,int>> L,R;

int ask(int a,int b,int c,int d){
	int res;
	cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
	cin>>res;
	return res;
}
void do_it(vector<pair<int,int>> vec,int b){
	if(vec.size()==0) return ;
	vector<int> l,r,res;
	for(auto [p,x] : vec){
		if(x==vec.back().S) continue ;
		if(ask(2,1,vec.back().S,x)==-1) l.pb(x);
		else r.pb(x);
	}
	for(auto x : l) res.pb(x);
	res.pb(vec.back().S);
	reverse(all(r));
	for(auto x : r) res.pb(x);
	if(b==1){
		//reverse(all(res));
	}
	for(auto x : res) ans.pb(x);
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	vector<pair<int,int>> vec;
	cin>>n;
	vec.pb({0,2});
	f(i,3,n+1){
		int res=ask(1,1,2,i)*ask(2,1,2,i);
		if(res<0){
			L.pb({-res,i});
		}
		else{
			R.pb({res,i});
		}
	}
	sort(all(L));
	sort(all(R));
	ans.pb(1);
	do_it(L,0);
	ans.pb(2);
	do_it(R,1);
	//reverse(all(vec));
	cout<<"0 ";
	f(i,0,n) cout<<ans[i]<<" "; cout<<endl;
}