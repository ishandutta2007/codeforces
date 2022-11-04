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

vector<int> p;
int lp[1000001];

bitset<200001> bs, res_;
int res[200001];
int ans;
int n,x,y;
vector<pair<int,int>> pf;
void gen(int div, int idx) {
	if(idx==sz(pf)) {
		int need=div/2-y;
		if(need<=x && need>0 && 2*(y+need)==div && res[need]) {
			ans=max(ans, div);
		}
		return ;
	}
	
	gen(div, idx+1);
	for(int j=0;j<pf[idx].yy;++j) {
		gen(div*=pf[idx].xx, idx+1);
	}
}


int main() {
	IO;
	for(ll i=2;i<=1000000;++i) {
		if(!lp[i]) {
			lp[i]=i;
			p.pb(i);
		}
		
		for(ll j=0;j<sz(p) && p[j]<=lp[i] && i*p[j]<=1000000;j++) {
			lp[i*p[j]]=p[j];
		}
	}
	
	
	cin>>n>>x>>y;
	vector<int> t(n+1);
	for(int i=0;i<=n;++i) {	
		cin>>t[i];
		bs.flip(t[i]);
	}
	
	for(int i=0;i<=n;++i) {
		res_|=(bs>>t[i]);
	}
	for(int i=0;i<=x;++i) {
		res[i]=res_[i];
	}
	
	int q;
	cin>>q;
	vector<int> pre(1000101, -2);
	for(int i=0;i<q;++i) {
		int x;
		cin>>x;
		if(pre[x]!=-2) {
			cout<<pre[x]<<" \n"[i==q-1];
			continue ;
		}
		int orig=x;
		pf.clear();
		while(x>1) {
			int akt=lp[x], cnt=0;
			while(x%akt==0) {
				x/=akt;
				cnt++;
			}
			pf.push_back({akt,cnt});
		}
		
		ans=0;
		gen(1,0);
		cout<<(pre[orig]=(!ans?-1:ans))<<" \n"[i==q-1];
		//~ return 0;
	}
	return 0;
}