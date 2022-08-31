#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T> ostream& operator<<(ostream& os, vector<T> V){
	os<<"[ "; for(auto v : V) os << v << " "; return os<<"]";
}
template<class L, class R> ostream& operator<<(ostream& os, pair<L, R> P){
	return os<< "(" << P.first << " , " << P.second << ")";
}
#define TRACE
#ifdef TRACE
template< typename Arg1>
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
void __f(const char* name, Arg1&& arg1){
	cout << name << ": "<< arg1 << endl;
}
template < typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma=strchr(names+1 , ','); cout.write(names, comma-names) << " : " << arg1 << " | ";
	__f(comma+1 , args...);
}
#else 
#define trace(...) 1
#endif
#define ll long long
#define ld long double
#define pll pair<ll, ll> 
#define pii pari<int, int>
#define F first
#define S second
#define I insert
#define pb push_back
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define vll vector<ll>

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(25);
	string s;cin>>s;
	vector<char> p;
	int len = s.length();
	vi cnt;
	int i,j;
	for(i=0;i<len;i++){
		if(i==0 or s[i]!=s[i-1])p.pb(s[i]), cnt.pb(1);
		else {
			auto z = cnt.back();
			cnt.pop_back();
			cnt.pb(z+1);
		}
	}
	int pz = p.size();
	if((pz%2)==0){
		cout<<0;
		return 0;
	}
	bool okay = 1;
	for(i=0;i<pz;i++){
		j = (pz-1)-i;
		if(p[i] != p[j] or (cnt[i]+cnt[j]<3)) okay=0;
	}
	int x = (pz-1)/2;
	if(!okay or cnt[x]<2)cout<<0;
	else cout<<cnt[x]+1;

	return 0;
}