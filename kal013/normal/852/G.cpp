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
const ll Mod[2] = {(ll)(1e9 + 9),(ll)(1e9+9)};
const ll prime[2] = {11,17};
ll power[100][2];

void pre(){
	power[0][0] = 1;
	power[0][1]=1;
	for(ll i = 1;i < 100 ; i++){
		For(j,2)
		power[i][j] = (power[i-1][j]*prime[j])%Mod[j];
	}
}

pll getHash(string &s){
	ll res[2] = {0,0};
	for(ll i = 0;i < s.size() ; i++){
		For(j,2){
		res[j] += (s[i]-'a'+1)*power[i][j];
		res[j] %= Mod[j];

		}
	}
	return {res[0],res[1]};
}


map<pll, ll> freq;
set<pll> allh;
void allHash(ll i , string &s , pll cu , ll skip){
	ll curr[2]={cu.F,cu.S};
	if(i == s.size()){
		allh.I(cu);
		return;
	}
	if(s[i] != '?'){
		For(j,2){
		curr[j] += (s[i]-'a'+1)*power[i-skip][j];
		curr[j] %= Mod[j];}
		allHash(i+1 , s , {curr[0],curr[1]} , skip);
	}
	else{

		for(char c = 'a' ; c <= 'e' ; c++){
			ll res[2]; 
			For(j,2){
				res[j]= curr[j] + (c-'a'+1)*power[i-skip][j];
			res[j] %= Mod[j];}
			allHash(i+1 , s , {res[0],res[1]} , skip);
		}
		allHash(i+1 , s , cu , skip+1);
	}

}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cout << setprecision(25);
	ll n , m; cin >> n >> m;
	pre();
	string s;
	for(ll i = 0;i < n; i++){
		cin >> s;
		freq[getHash(s)]++;
	}
	for(ll i = 0;i < m; i++){
		cin >> s;
		allh.clear();
		allHash(0 , s , {0,0} , 0);
		// trace(allh);
		ll ans = 0;
		for(auto it : allh){
			ans += freq[it];
		}
		cout << ans << '\n';
	}


	return 0;
}