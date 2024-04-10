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

bitset<1000011> bs;
int main() {
	IO;
	int n;
	cin>>n;
	string t;
	cin>>t;
	array<int,2> last={n,n};
	vector<int> nxt(n);
	for(int i=n-1;i>=0;i--) {
		if(t[i]=='?') {
			nxt[i]=min(last[0]==n?n:nxt[last[0]], last[1]==n?n:nxt[last[1]]);
		}else {
			nxt[i]=last[1-(t[i]-'0')];
		}
		
		last[t[i]-'0']=i;
	}
	
	vector<pair<int,int>> lst;
	for(int i=0;i<n;++i) {
		lst.pb({nxt[i]-i, i});
	}
	sort(all(lst));
	reverse(all(lst));
	
	
	int cnt=n;
	bs.flip();
	
	vector<int> ress;ress.reserve(n);
	for(int i=1;i<=n;++i) {
		while(!lst.empty() && lst.back().xx<i) {
			cnt--;
			bs[lst.back().yy]=0;
			lst.pop_back();
		} 
		
		int ans=0;
		if(cnt>0) {
			int j=bs._Find_first();
			while(j<n) {
				j=bs._Find_next(j+i-1);
				ans++;
			}
		}
		ress.pb(ans);
	
		
		//~ int j=0;
		//~ int ans=0;
		//~ while(j<n) {
			//~ if(nxt[j]-j>=i) {
				//~ ans++;
				//~ j+=i;
			//~ }else j++;
		//~ }
		//~ cout<<ans<<" \n"[i==n];
	}
	for(auto i:ress) cout<<i<<" ";
	cout<<"\n";
	
	return 0;
}