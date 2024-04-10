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


int main() {
	IO;
	int T;
	cin>>T;
	while(T--) {
		int n,k;
		cin>>n>>k;
		string t;
		cin>>t;
		int j;
		vector<vector<int>> sima;
		vector<vector<int>> jo;
		bool volt=false;
		for(int i=0;i<n;i=j) {
			j=i;
			
			if(t[i]=='L') {
				if(volt) {
					while(j<n && t[j]=='L') j++;
					if(j==n) {
						sima.pb({});
						for(int k=i;k<j;++k) {
							sima.back().pb(k);
						}
					}else {
						jo.pb({});
						for(int k=i;k<j;++k) {
							jo.back().pb(k);
						}
					}
				}else {
					sima.pb({j});
					j++;
				}
			}else {
				volt=true;
				j++;
			}
		}
		reverse(all(sima)); //ne legyen elol az elsok
		sort(all(jo), [&](vector<int>& egyik, vector<int>& masik) -> bool {
			return sz(egyik)<sz(masik);
		});
		
		vector<vector<int>> osz;
		for(auto& i:jo) osz.pb(i);
		for(auto& i:sima) osz.pb(i);
		
		string uj=t;
		for(auto& i:osz) {
			for(auto& j:i) {
				if(k) {
					k--;
					uj[j]='W';
				}
			}
		}
		
		int ans=0;
		for(int i=0;i<sz(uj);++i) {
			if(uj[i]=='W') ans++;
			if(i>0 && uj[i]=='W' && uj[i-1]=='W') ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}