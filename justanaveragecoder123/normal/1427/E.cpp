#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<cassert>
#include<cassert>
#include<unordered_map>
#include<unordered_set>
#include<functional>
#include<queue>
#include<stack>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<sstream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<numeric>
#include<random>
#include<chrono>
#include<bitset>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define sz(x) (int)(x).size()
#define gc getchar
#define IO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mp make_pair

#ifndef ONLINE_JUDGE
#  define LOG(x) (cerr << #x << " = " << (x) << endl)
#else
#  define LOG(x) ((void)0)
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double PI=acos(-1);
const ll INF = 1LL<<62;
const ll MINF = -(1LL<<62);

template<typename T> T getint() {
	T val=0;
	char c;
	
	bool neg=false;
	while((c=gc()) && !(c>='0' && c<='9')) {
		neg|=c=='-';
	}

	do {
		val=(val*10)+c-'0';
	} while((c=gc()) && (c>='0' && c<='9'));

	return val*(neg?-1:1);
}

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); uniform_int_distribution<int>(0, n-1)(rng)


ll extended_gcd(ll a, ll b, ll* x, ll* y) {
	if(b==0) {
		*x=1;
		*y=0;
		return a;
	}
	
	ll x0, y0;
	ll gcd=extended_gcd(b, a%b, &x0, &y0);
	
	*x=y0;
	*y=x0-(a/b)*y0;
	
	assert((*x)*a+(*y)*b==gcd);
	
	return gcd;
}

ll inverse(ll a, ll m) {
	ll x,y;
	extended_gcd(a,m,&x,&y);
	assert((x*a-1)%m==0);
	return x;
}


void basic(vector<string>& res, ll n){
	ll akt=n;
	for(ll i=2;akt<1LL<<60;++i) {
		res.pb(to_string(akt)+" + "+to_string(akt));
		akt*=2;
	}
}

void add(vector<string>& res, ll n, ll x) {
	ll prev=-1;
	ll sum=0;
	for(ll i=60;i>=0;i--) {
		if((1LL<<i)&x) {
			if(prev!=-1) {
				res.pb(to_string(sum)+" + "+to_string(n*(1LL<<i)));
			}
			prev=i;
			sum+=(1LL<<i)*n;
		}
	}
}

vector<string> solve(ll n) {
	vector<string> res;
	basic(res, n);
	
	ll egyik=n;
	ll masik=-1;
	for(ll i=1;i<100000&&masik==-1;++i) {
		for(ll j=i+1;masik==-1;j+=i) {
			if(gcd((n*i)^(n*j), n)==1 && ((n*i)^(n*j))&1 && abs(((n*i)^(n*j))-n)>2) {
				add(res, n, i);
				add(res, n, j);
				res.pb(to_string(n*i)+" ^ "+to_string(n*j));
				masik=(n*i)^(n*j);
			}
		}
	}
	assert(masik!=-1);
	
	basic(res, masik);

	ll coef_egyik, coef_masik;
	
	extended_gcd(egyik, masik,&coef_egyik,&coef_masik);
	
	coef_egyik=abs(coef_egyik);
	coef_masik=abs(coef_masik);
	LOG(coef_egyik);
	LOG(coef_masik);
	LOG(egyik);
	LOG(masik);
	while(1) {
		
		if(((coef_egyik*egyik)%2==0 && coef_egyik*egyik>coef_masik*masik) || ((coef_masik*masik)%2==0 && coef_egyik*egyik<coef_masik*masik)) {
			coef_egyik+=masik;
			coef_masik+=egyik;
		} else break ;
	}
	
	add(res, egyik, coef_egyik);
	add(res, masik, coef_masik);
	
	assert(((egyik*coef_egyik)^(masik*coef_masik))==1);
	
	res.pb(to_string((egyik*coef_egyik))+" ^ "+to_string((masik*coef_masik)));
	
	return res;
}

int main() {
	IO;
	ll n;
	cin>>n;

	//~ for(int i=1;i<=999999;i+=2) {
		//~ LOG(i);
		//~ solve(i);
	//~ }
	vector<string> ans=solve(n);
	cout<<sz(ans)<<"\n";
	for(auto i:ans) {
		cout<<i<<"\n";
	}
	
	
	return 0;
}