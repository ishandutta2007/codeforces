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

const int N=1050;
string res[N];
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(25);
	int n,L,k;
	cin>>n>>L>>k;
	string s;
	cin>>s;
	vector<char> tp;
	for(auto e:s) tp.pb(e);
	sort(all(tp));
	int l=1;int cu=0;

	int cnt=0;
	while(l<k && cu<tp.size() && cnt<L){
		++cnt;
		for(int j=l;j<=k;++j){
			res[j]+=tp[cu++];
		}
		l=k;
		while(res[l-1].size()>0 && res[l-1].back()==res[k].back()) --l;
	}
	while(res[k].size()<L){
		res[k]+=tp[cu++];
	}

	for(int i=1;i<=n;++i){
		while(res[i].size()<L) res[i]+=tp[cu++];
		cout<<res[i]<<endl;
	}
	
	
	return 0;
}