#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

template<class T> ostream& operator <<(ostream& os, vector<T> V){
	os << "[ "; for(auto v : V) os << v << " "; return os <<"]";
}
template<class L, class R> ostream& operator<<(ostream& os , pair<L, R> P){
	os <<"(" << P.first << " , " << P.second << ")";
}
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template<typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cout << name << " : " << arg1 << endl;
}
template<typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma=strchr(names+1 , ',');
	cout.write(names, comma-names) << " : " << arg1 << " | ";
	__f(comma+1 , args...);
}
#else
#define trace(...) 1
#endif 
#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define pii pair<ll, ll>
#define vll vector<ll>
#define vi vector<ll>
#define I insert
#define F first
#define S second
#define pb push_back
#define endl "\n"
#define all(x) x.begin(), x.end()
#define For(i,n) for(ll i = 0;i < n; i++)
#define Rep(i,n) for(ll i = 1;i <= n ;i++)
#define ld long double
// struct pt{
// 	ld x,y;
// 	pt(ld x,ld y): x(x),y(y){}
// 	pt operator - (const pt & p) const {
// 		return pt(x-p.x,y-p.y);
// 	}
// 	ld operator *( const pt& p) const {
// 		return x*p.x+y*p.y;
// 	}
// 	ld operator ^ (const pt & p) const {
// 		return x*p.y-y*p.x;
// 	}
// };
// ld area(pt x,pt y,pt z){
// 	return abs(((x-y)^(z-y)));
// }
const ll maxn=1e6+5;
ll B[maxn];
ll ans[maxn];
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cout << setprecision(25);
	ll n;
	cin>>n;
	for(ll i=0;i<n;++i){
		cin>>B[i];
	}
	vector<pair<ll,ll>>  vals;
	for(ll i=0;i<n;++i){
		ll x1=B[i],x2=(B[(i+1)%n]);
		vals.pb({x1+x2,i});
	// 	if (x2>=n-x1){
	// 		cout<<n-1<<" ";
	// 	}
	// 	else{
	// 		cout<<0<<" ";
	// 	}
	// }
	}
	sort(all(vals));
	For(i,vals.size()){
		ans[vals[i].S]=i;
	}
	For(i,n){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}