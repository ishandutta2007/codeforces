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

template<typename T>
vector<int> calc_next(vector<int>& t, T cmp, bool rev=false) {
	if(rev) reverse(all(t));
	vector<int> ans(sz(t));
	
	stack<pair<int,int>> st; //val,pos
	for(int i=0;i<sz(t);++i) {
		while(!st.empty() && cmp(st.top().xx, t[i])) st.pop();
		ans[i]=(st.empty()?-1:st.top().yy);
		st.push({t[i], i});
	}
	
	if(rev) {
		reverse(all(t));
		reverse(all(ans));
		for(auto& i:ans) i=sz(t)-i-1;
	}
	
	return ans;
}



int main() {
	IO;
	int T;
	cin>>T;
	while(T--) {
		int n;
		cin>>n;
		vector<int> t(n);
		for(int i=0;i<n;++i) cin>>t[i];
		vector<int> prv=calc_next(t, greater_equal<int>(), false);
		vector<int> nxt=calc_next(t, greater_equal<int>(), true);
		vector<int> life(n);
		vector<pair<int,int>> evs;
		for(int i=0;i<n;++i) {
			life[i]=nxt[i]-prv[i]-1;
			evs.push_back({life[i], t[i]});
		}
		sort(all(evs));
		string ans(n,'0');
		multiset<int> s;
		map<int,int> cnt;
		
		for(auto i:t) {
			s.insert(i);
			cnt[i]++;
		}
		
		int van=0;
		for(auto i:cnt) if(i.yy>1) van++;
		
		for(auto i:evs) {
			//~ LOG(i.xx);
			//~ LOG(i.yy);
			if(sz(s)==*prev(s.end()) && !van && sz(s)==n-i.xx+1) {
				ans[i.xx-1]='1';
			}
			s.erase(s.lower_bound(i.yy));
			if(cnt[i.yy]==2) {
				van--;
			}
			cnt[i.yy]--;
		}
		cout<<ans<<"\n";
	}
	return 0;
}