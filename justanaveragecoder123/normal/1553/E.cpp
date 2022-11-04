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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); 

int main() {
	IO;
	int T;
	cin>>T;
	while(T--) {
		int n,m;
		cin>>n>>m;
		vector<int> p(n);
		for(int i=0;i<n;++i) {
			cin>>p[i];
		}
		
		vector<int> ans;
		for(int j=0;j<50;++j) {
			int pos=uniform_int_distribution<int>(0, n-1)(rng);
			
			vector<int> ok(n);
			int cnt=1;
			ok[pos]=1;
			for(int i=1;i<n;++i) {
				if(p[(pos+i)%n]==((p[pos]+i-1)%n+1)) {
					cnt++;
					ok[(pos+i)%n]=1;
				}
			}
			
			int shift=(pos-p[pos]+1+n)%n;
			
			vector<int> pp(n);
			
			iota(all(pp), 1);
			rotate(pp.rbegin(), pp.rbegin()+shift, pp.rend());
			
			vector<int> inv(n+1);
			for(int i=0;i<n;++i) {
				inv[pp[i]]=i;
			}
			
			vector<int> nxt(n+1);
			int need=0;
			for(int i=0;i<n;++i) {
				if(!ok[i]) {
					nxt[inv[p[i]]]=i;
					need++;
				}
			}
			
			
			vector<int> volt(n+1);
			for(int i=0;i<n;++i) {
				if(!volt[i] && !ok[i]) {
					need--;
					int akt=i;
					while(!volt[akt]) {
						volt[akt]=1;
						akt=nxt[akt];
					}
				}
			}
			
			if(need<=m) {
				ans.pb(shift);
			}
			
			//~ return 0;
		}
		
		sort(all(ans));
		ans.resize(distance(ans.begin(), unique(all(ans))));
		
		cout<<sz(ans)<<" ";
		for(auto i:ans) cout<<i<<" ";
		cout<<"\n";
		
		cout<<flush;
	}
	return 0;
}