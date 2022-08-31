#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
 os << "[ "; for(auto v : V) os << v << " "; return os << "]";}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
	return os << "(" << P.first << "," << P.second << ")";}

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cout << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...) 1
#endif


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


int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<setprecision(25);
	string s;
	cin>>s;
	ll i,j,k;
	string p = "CODEFORCES";
	ll m = s.length();
	ll del = m - p.length();
	if(del<0){cout<<"NO";return 0;}
	if(del==0){
		if(p==s){cout<<"YES";}
		else cout<<"NO";return 0;
	}
	for(i=0;i<m;i++){
		j = i+del-1;
		if(j>=m)break;
		ll x=0;bool done = true;
		for(k=0;k<m;k++){
			if(k==i){k=j;continue;}
			if(p[x]!=s[k]){done=false;break;}
			x++;
		}
		if(done){cout<<"YES";return 0;}
	}
	cout<<"NO";
}