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

vector<int> adj[200001][2];

typedef pair<ll,ll> mypair;
bool operator<(const mypair& egyik, const mypair& masik) {
	if(egyik.xx<=30 && masik.xx<=30) {
		//~ LOG((1LL<<(egyik.xx))-1+egyik.yy);
		//~ LOG((1LL<<(masik.xx))-1+masik.yy);
		return (1LL<<(egyik.xx))-1+egyik.yy<(1LL<<(masik.xx))-1+masik.yy;
	}
	if(egyik.xx==masik.xx) return egyik.yy<masik.yy;
	return egyik.xx<masik.xx;;
}

struct st {
	mypair len;
	pair<int,int> pos;
	bool operator<(const st& masik) const {
		return masik.len<len;
	};
};
const ll mod=998244353;
ll fp(ll a,ll b) {
	if(b==0) return 1;
	ll fele=fp(a,b/2);
	ll ans=fele*fele%mod;
	if(b&1) ans=ans*a%mod;
	return ans;
}

int nxt(int x) {
	if(x<=19) return x+1;
	else return x-1;
}
mypair mn[200001][21];
int main() {
	IO;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;++i) {
		int a,b;
		
		cin>>a>>b;
		adj[a][0].pb(b);
		adj[b][1].pb(a);
	}
	
	//~ LOG(((mypair){1,1}>(mypair){0,3}));
	priority_queue<st> pq;
	pq.push({{0,0},{1,0}});
	for(int i=1;i<=n;++i) {
		for(int j=0;j<=20;++j) {
			mn[i][j]={30*n,30*n};
		}
	}
	mn[1][0]={0,0};
	mypair ans={30*n,30*n};
	while(!pq.empty()) {
		auto fr=pq.top();
		pq.pop();
		//~ cerr<<fr.pos.xx<<";"<<fr.pos.yy<<" "<<fr.len.xx<<" "<<fr.len.yy<<"\n";
		if(fr.pos.xx==n) {
			if(fr.len<ans) ans=fr.len;
			//~ cerr<<ans.xx<<" "<<ans.yy<<"\n";
		}
		if(mn[fr.pos.xx][fr.pos.yy]<fr.len) continue ;
		if((mypair){fr.len.xx+1,fr.len.yy}<mn[fr.pos.xx][nxt(fr.pos.yy)]) {
			pq.push({mn[fr.pos.xx][nxt(fr.pos.yy)]={fr.len.xx+1,fr.len.yy}, {fr.pos.xx, nxt(fr.pos.yy)}});
		}
		
		for(auto j:adj[fr.pos.xx][fr.pos.yy&1]) {
			mypair cost={fr.len.xx, fr.len.yy+1};
			pair<int,int> to={j, fr.pos.yy};
			if(cost<mn[to.xx][to.yy]) {
				pq.push({mn[to.xx][to.yy]=cost, to});
			}
		}
	}
	//~ LOG(ans.xx);
	//~ LOG(ans.yy);
	ll res=fp(2,ans.xx)-1+ans.yy;
	res%=mod;
	if(res<0) res+=mod;
	cout<<res<<"\n";
	

	return 0;
}