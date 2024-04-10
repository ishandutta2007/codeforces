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

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


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
		vector<string> s(n);
		for(int i=0;i<n;++i) cin>>s[i];
		
		vector<int> cnt(2*n);
		array<int,3> mod3={0,0,0};
		for(int i=0;i<2*n;++i) {
			int x=0, y=i;
			while(y>=0) {
				if(x>=0 && y>=0 && x<n && y<n && s[x][y]=='X') {
					cnt[i]++;
					mod3[i%3]++;
				}
				x++;
				y--;
			}
		}
		int best=0;
		if(mod3[best]>mod3[1]) best=1;
		if(mod3[best]>mod3[2]) best=2;
		for(int i=0;i<2*n;++i) {
			if(best==i%3) {
				int x=0, y=i;
				while(y>=0) {
					if(x>=0 && y>=0 && x<n && y<n && s[x][y]=='X') {
						s[x][y]='O';
					}
					x++;
					y--;
				}
			}
		}
	
	
		for(auto i:s) {
			cout<<i<<"\n";
		}
	}
	return 0;
}