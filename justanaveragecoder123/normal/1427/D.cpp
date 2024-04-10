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

int n;
vector<int> p;

vector<vector<int>> solve(vector<pair<int,int>> p) {
	//~ for(auto i:p) {
		//~ cerr<<"("<<i.xx<<";"<<i.yy<<")";
	//~ }cerr<<"\n";
	if(sz(p)==1) return {};
	if(sz(p)==2) {
		if(p[0].xx<p[1].xx) return {};
		return {{p[0].yy, p[1].yy}};
	}
	for(int i=1;i<sz(p);++i) {
		if(p[i].xx==p[i-1].xx+1) {
			vector<pair<int,int>> uj;
			for(int j=0;j<sz(p);++j) {
				if(j==i) continue ;
				
				if(j==i-1) {
					uj.pb({p[i-1].xx, p[i-1].yy+p[i].yy});
					j++;
				}else {
					uj.pb({p[j].xx-(p[j].xx>=p[i-1].xx), p[j].yy});
				}
			}
			
			return solve(uj);
		}
	}
	
	for(int i=0;i<sz(p);++i) {
		for(int j=i+1;j<sz(p);++j) {
			if(p[j].xx+1==p[i].xx) {

				vector<int> op;
				vector<vector<pair<int,int>>> lst;
				if(i>0) {
					op.pb(0);
					lst.pb({});
					for(int k=0;k<i;++k) {
						op.back()+=p[k].yy;
						lst.back().pb(p[k]);
					}
				}
				op.pb(0);
				lst.pb({});
				for(int k=i;k<j;++k) {
					op.back()+=p[k].yy;
					lst.back().pb(p[k]);
				}
				op.pb(p[j].yy);
				lst.pb({p[j]});
				
				if(j+1<sz(p)) {
					op.pb(0);
					lst.pb({});
					for(int k=j+1;k<sz(p);++k) {
						op.back()+=p[k].yy;
						lst.back().pb(p[k]);
					}
				}
				
				vector<pair<int,int>> uj;
				reverse(all(lst));
				for(auto k:lst) {
					for(auto l:k) uj.pb(l);
				}
				
				auto ans=solve(uj);
				reverse(all(ans)); ans.pb(op);
				reverse(all(ans));
				return ans;
			}
		}
	}
	
	assert(0);
}

vector<int> applyops(vector<int> to, vector<vector<int>> ops) {
	for(auto i:ops) {
		vector<vector<int>> lst;
		lst.pb({});
		int k=0;
		for(int j=0;j<sz(to);++j) {
			if(i[k]==sz(lst.back())) {
				lst.pb({});
				k++;
			}
			lst.back().pb(to[j]);
		}
		for(auto j:lst) {
			cerr<<"{";
			for(auto k:j) cerr<<k<<",";
			cerr<<"}";
		}cerr<<"\n";
		
		
		reverse(all(lst));
		to={};
		for(auto j:lst) for(auto k:j) to.pb(k);
	}
	return to;
}

int main() {
	IO;
	cin>>n;
	vector<pair<int,int>> p(n);
	#ifndef LOCAL
	for(int i=0;i<n;++i) {
		cin>>p[i].xx;
		p[i].yy=1;
	}
	#else
	for(int i=0;i<n;++i) {
		p[i].xx=i+1;
		p[i].yy=1;
	}
	random_shuffle(all(p));
	#endif
	auto ans=solve(p);
	cout<<sz(ans)<<"\n";
	for(auto& i:ans) {
		cout<<sz(i)<<" ";
		for(auto j:i) cout<<j<<" ";
		cout<<"\n";
	}
	#ifdef LOCAL
	vector<int> pp;
	for(auto i:p) pp.pb(i.xx);
	int ind=1;
	for(auto i:applyops(pp, ans)) {
		LOG(i);
		assert(i==ind++);
	}
	#endif
	
	return 0;
}