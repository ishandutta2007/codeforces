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
		int n;
		cin>>n;
		vector<ll> t(n);
		ll sum=0;
		for(int i=0;i<n;++i) {
			cin>>t[i];
			sum+=t[i];
		}
		ll egy=sum/n;
		if(sum%n!=0) {
			cout<<"-1\n";
			continue ;
		}else {
			bool ok=true;
			vector<array<ll,3>> ans;
			auto op=[&](ll a, ll b, ll x) {
				t[a]-=(a+1)*x;
				ok&=t[a]>=0;
				t[b]+=(a+1)*x;
				ok&=t[b]>=0;
				ans.pb({a+1,b+1,x});
			};
			
			vector<pair<ll,int>> needs;
			for(int i=1;i<n;++i) {
				ll le=i+1;
				ll can=t[i]/le;
				if(can>0) {
					op(i,0,can);
				}else {
					needs.push_back({le-t[i], i});
				}
			}
			
			sort(all(needs));
			for(auto i:needs) {
				op(0,i.yy,i.xx);
				op(i.yy,0,1);
			}
			
			needs.clear();
			for(int i=1;i<n;++i) {
				if(t[i]>egy) {
					ll need=(i+1)+egy;
					needs.pb({need-t[i],i});
					//~ op(0,i,need-t[i]);
					//~ op(i,0,1);
				}
			}
			
			sort(all(needs));
			for(auto i:needs) {
				op(0,i.yy,i.xx);
				op(i.yy,0,1);
			}
			
			for(int i=1;i<n;++i) {
				if(t[i]<egy) {
					ll need=egy-t[i];
					op(0,i,need);
				}
			}
			
			if(ok) {
				assert(sz(ans)<=3*n);
				cout<<sz(ans)<<"\n";
				for(auto i:ans) cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<"\n";
				int eq=1;
				for(int i=1;i<n;++i) eq&=t[i]==t[i-1];
				assert(eq);
			}else cout<<"-1\n";
			//~ for(auto i:t) LOG(i);
		}
	}
	return 0;
}