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

int n,m,k;
const int MAXN=200001;
vector<pair<int,int>> adj[MAXN];

int conv(int x, int y) {
	return x*k+y-1;
}
pair<int,int> iconv(int x) {
	return {x/k, x%k+1};
}


vector<int> in[MAXN];
int no[500][500];

int ans=0;
int curr[500];
void gen(int x) {
	if(x>k) {
		//~ for(int i=1;i<=k;++i) cerr<<curr[i]<<" ";cerr<<"\n";
		ans++;
		return ;
	}
	
	for(int i=1;i<=x;++i) {
		curr[x]=i;
		bool ok=true;
		for(int k=1;k<=x;++k) {
			ok&=no[conv(k,curr[k])][conv(x, i)]==0;
		}
		if(ok) gen(x+1);
		
	}
	curr[x]=0;
}

int main() {
	IO;
	cin>>n>>m>>k;
	for(int i=0;i<m;++i) {
		int a,b,c;
		cin>>a>>b>>c;
		adj[a].pb({c,b});
	}
	
	for(int i=1;i<=n;++i) {
		sort(all(adj[i]));
		for(int j=0;j<sz(adj[i]);++j) {
			in[adj[i][j].yy].pb(conv(sz(adj[i]), j+1));
		}
	}
	
	for(int i=1;i<=n;++i) {
		
		map<int,int> cnt;
		for(int j:in[i]) cnt[j]++;
		for(auto j:cnt) {
			if(j.yy>1) {
				no[j.xx][j.xx]=1;
			}
			for(auto k:cnt) {
				if(j.xx!=k.xx) {
					no[j.xx][k.xx]=1;
				}
			}
		}
	}
	
	gen(1);
	cout<<ans<<"\n";
	return 0;
}