#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) builtin_popcount(x)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=2e6+99;

ll n,t;
vector<ll> v;
vector<pair<char,pair<ll,ll> > > ans;

void Add(ll x,ll y,int type){
	char c;
	if(type==0) c='^';
	else c='+';
	ans.pb(mp(c,mp(x,y)));
	int i=ans.size()-1;
	//cout<<ans[i].S.F<<' '<<ans[i].F<<' '<<ans[i].S.S<<endl;
	
}
void make(ll x){
	if(x==0) return ;
	make(x/2);
	Add(x/2*n,x/2*n,1);
	if(x&1) Add(x*n-n,n,1);
}
void check(ll x){
	ll cp=x;
	f(i,0,v.size()){
		minm(x,x^v[i]);
	}
	if(x!=0){
		x=cp;
		make(x/n);
		f(i,0,v.size())
			if((x^v[i])<x){
				Add(x,v[i],0);
				x^=v[i];
			}
	   v.pb(x);
	   sort(v.begin(),v.end());
	   reverse(v.begin(),v.end());
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	v.pb(n);
	Add(n,n,0);
	f(i,2,N)
		check(n*i);
	cout<<ans.size()<<endl;
	f(i,0,ans.size())
		cout<<ans[i].S.F<<' '<<ans[i].F<<' '<<ans[i].S.S<<endl;
}