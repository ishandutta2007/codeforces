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
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define sz(x) (int)(x).size()
#define gc getchar
#define IO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mp make_pair
#define ins insert

#ifndef ONLINE_JUDGE
#  define LOG(x) (cerr << #x << " = " << (x) << endl)
#else
#  define LOG(x) ((void)0)
#endif

using ll = long long;
using ull = unsigned long long ;
using ld = long double ;
using str = string;
using ordered_set=tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update>;

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

const int MAXN = 1e6+10;
int lp[MAXN];
vector<int> ps;

void sieve() {
	for(int i=2;i<MAXN;++i) {
		if(!lp[i]) {
			lp[i]=i;
			ps.push_back(i);
		}
		
		for(int j=0;j<sz(ps) && i*ps[j]<MAXN && ps[j]<=lp[i];++j) {
			lp[i*ps[j]]=ps[j];
		}
	}
}

vector<pair<int,int>> pfactors(int x) {
	vector<pair<int,int>> res;
	while(x>1) {
		int p=lp[x];
		res.push_back({p, 0});
		while(x%p==0) x/=p, res.back().yy++;
	}
	return res;
}


void divs_gen(int ind, int div, vector<pair<int,int>>& pfacts, vector<int>& res) {
	if(ind==sz(pfacts)) {
		res.push_back(div);
		return ;
	}
	
	divs_gen(ind+1, div, pfacts, res);
	for(int i=0;i<pfacts[ind].yy;++i) {
		div*=pfacts[ind].xx;
		divs_gen(ind+1, div, pfacts, res);
	}
}

vector<int> divs(int x) {
	vector<int> res;
	vector<pair<int,int>> pfacts=pfactors(x);
	divs_gen(0, 1, pfacts, res);

	return res;
}

int main() {
	IO;
	sieve();
	
	int T;
	cin>>T;
	while(T--) {
		int n,e;
		cin>>n>>e;
		vector<int> t(n);
		for(int i=0;i<n;++i) {
			cin>>t[i];
		}
		
		vector<int> dp0(n), dp1(n);
		ll ans=0;
		for(int i=n-1;i>=0;i--) {
			if(t[i]==1) {
				dp0[i]=1+(i+e<n?dp0[i+e]:0);
				dp1[i]=(i+e<n?dp1[i+e]:0);
				
				ans+=dp1[i];
				
			}else if(lp[t[i]]==t[i]) {
				dp1[i]=1+(i+e<n?dp0[i+e]:0);
				
				ans+=dp1[i]-1;
			}
		}
		
		cout<<ans<<"\n";
	}
	return 0;
}