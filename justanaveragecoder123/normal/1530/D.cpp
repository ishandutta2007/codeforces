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

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); uniform_int_distribution<int>(0, n-1)(rng)


int main() {
	IO;
	int T;
	cin>>T;
	while(T--) {
		int n;
		cin>>n;
		vector<int> a(n), b(n), have(n+1);
		for(int i=0;i<n;++i) cin>>a[i];
		for(int i=0;i<n;++i) {
			if(!have[a[i]]) {
				have[a[i]]=1;
				b[i]=a[i];
			}
		}
		
		vector<int> rem;
		for(int j=1;j<=n;++j) {
			if(!have[j]) rem.push_back(j);
		}
		
		if(sz(rem)==0) {
			cout<<n<<"\n";
			for(auto i:b) cout<<i<<" ";cout<<"\n";
		}else {
			//~ for(auto i:b) cerr<<i<<" ";cerr<<"\n";
			if(sz(rem)>1) {
				sort(all(rem));
				vector<int> pos;

				for(int j=0;j<sz(b);++j) {
					if(!b[j]) {
						pos.push_back(j+1);
					}
				}
				
				while(1) {
					bool swp=false;
					for(int i=0;i<sz(pos);++i) {
						if(pos[i]==rem[i]) {
							swp=true;
							swap(rem[i], rem[(i+1)%sz(rem)]);
						}
					}
					if(!swp) break ;
				}
				
				for(int i=0;i<sz(pos);++i) b[pos[i]-1]=rem[i];
				
				
				
				cout<<n-sz(rem)<<"\n";
				for(auto i:b) cout<<i<<" ";
				cout<<"\n";
			}else {
				if(b[rem[0]-1]==0) {
					for(int i=0;i<sz(a);++i) {
						if(a[i]==a[rem[0]-1]) {
							b[i]=rem[0];
							b[rem[0]-1]=a[rem[0]-1];
							break ;
						}
					}
					
					cout<<n-sz(rem)<<"\n";
					for(auto i:b) cout<<i<<" ";
					cout<<"\n";
				
				}else {
					for(int j=0;j<sz(b);++j) {
						if(!b[j]) {
							b[j]=rem[0];
							break ;
						}
					}
					
					cout<<n-sz(rem)<<"\n";
					for(auto i:b) cout<<i<<" ";
					cout<<"\n";
				}
			}
		}
		
	}
	return 0;
}