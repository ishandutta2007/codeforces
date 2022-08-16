#include <bits/stdc++.h>
using namespace std;

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ ";
    for(auto v : V) os << v << " ";
    return os << "]";
}
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";
}
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.F<<":"<<m.S<<") ";
    return os<<"}";
}

#define cerr cout

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...) 1
#endif

// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds;
// #define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_Node_update>
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
// erase,insert same as normal set

#define ll long long
#define ld long double
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define I insert 
#define pb push_back
#define F first
#define S second
#define endl "\n"
#define all(v) (v).begin(),(v).end()
#define For(i,n) for(ll i=0;i<(ll)n;++i)
#define Rev(i,n) for(ll i=(ll)n-1;i>=0;--i)
#define Rep(i,n) for(ll i=1;i<=(ll)n;++i)
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
typedef pair<pii,ll> ppi;
typedef vector<pii> vpi;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MP make_pair

// #define d0(x) cout<<(x)<<" "
// #define d1(x) cout<<(x)<<endl
// #define d2(x,y) cout<<(x)<<" "<<(y)<<endl
// #define d3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl


// // const ll mod=1e9+7;
// inline ll mul(ll a,ll b){return (a*1ll*b)%mod;}
// inline ll add(ll a,ll b){a+=b;if(a>=mod)a-=mod;return a;}
// inline ll sub(ll a,ll b){a-=b;if(a<0)a+=mod;return a;}
// inline ll power(ll a,ll b){ll rt=1;while(b>0){if(b&1)rt=mul(rt,a);a=mul(a,a);b>>=1;}return rt;}
// inline ll inv(ll a){return power(a,mod-2);}
// inline void modadd(ll &a,ll &b){a+=b;if(a>=mod)a-=mod;} 
const ll INF=1e18;
const ll maxn=3e5+100;
struct Node{
	ll a,b,t,id;
	friend ostream& operator << (ostream & os, const Node& n){
		return os<<"("<<n.id<<" "<<n.a<<" "<<n.b<<" "<<n.t<<")";
	}

	bool operator < (const Node& p) const{
		return t<p.t;
	}
	bool operator > (const Node& p) const{
		return (t>p.t || (t==p.t && id>p.id));
	}
};
Node A[maxn];
bool done[maxn];
bool cmp(Node i,Node j){
	return (i.a<j.a || (i.a==j.a && i.b<j.b) || (i.a==j.a && i.b==j.b && i.t<j.t) || (i.a==j.a && i.b==j.b && i.t==j.t && i.id<j.id));
}
void solve(){
	ll n;
	cin>>n;

	Rep(j,n){
		cin>>A[j].a>>A[j].b>>A[j].t;
		A[j].id=j;
		A[j].b-=A[j].t;
	}
	sort(A+1,A+n+1,cmp);
	vector<pair<pll,Node> > stk;
	vector<ll> tims;

	Rep(j,n) {
		// trace(A[j]);
		stk.pb({{A[j].a,0},A[j]});
		stk.pb({{A[j].b+1,-1},A[j]});
		tims.pb(A[j].a);
		tims.pb(A[j].b+1);
	}
	sort(all(stk));
	sort(all(tims));
	tims.pb(INF);

	ll ct=0;
	ll con=0;
	ll res=0;
	priority_queue<Node, vector<Node> ,greater<Node> > HP;
	for(ll i=0;i<stk.size();++i){
		// trace(ct,i,stk[i],tims[i]);
		if (con==0){
			ct=max(tims[i],ct);
		}
		else{
			auto X=HP.top();
			// trace(X,done[1]);
			while(done[X.id]){
				HP.pop();
				if (HP.empty()) break;
				X=HP.top();

			}
			if (ct<tims[i] && !HP.empty()){
				ll x=(tims[i]-ct+X.t-1)/X.t;
				// trace(x,X);
				res+=x;
				ct+=X.t*x;
			}
		}
		// trace(ct,i,stk[i],tims[i],res);

		auto Y=stk[i].S;
		if (stk[i].F.S==-1){
			done[Y.id]=1;
			--con;
		}
		else{
			ct=min(ct,tims[i]+Y.t);
			HP.push(Y);

			++con;
		}
		// trace(ct,i,stk[i],tims[i],res);

	}
	cout<<res<<endl;

}
int main(){
	fio; cout<<fixed<<setprecision(25);
	ll t=1;
	// cin>>t;
	while(t--){
		solve();

	}

}