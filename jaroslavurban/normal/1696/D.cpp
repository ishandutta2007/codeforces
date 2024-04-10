#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// views::zip, ranges::sort

typedef long long ll;
typedef long double ld;

template<typename O>
struct SparseTable{
	using T=typename O::T;
	int n,p;
	vector<vector<T>>dp;
	vector<int>lg;
	SparseTable(vector<T>a={1}):n(a.size()),p(log2(n)+1),dp(p,vector<T>(n)),lg(n+1){
		dp[0]=a;
		for(int i=2;i<=n;++i)lg[i]=lg[i/2]+1;
		for(int i=1;i<p;++i)
			for(int j=0,j2=(1<<(i-1));j2<n;++j,++j2)
				dp[i][j]=O::uni(dp[i-1][j],dp[i-1][j2]);
	}
	// inclusive, exclusive
	T query(int l,int r){
		if (l >= r) return -1;
		int x=lg[r-l];
		return O::uni(dp[x][l],dp[x][r-(1<<x)]);
	}
};

template<typename O>
struct ST{
	using T=typename O::T;
	int n;vector<T>t;
	ST(vector<T>a):n(1<<int(log2(a.size())+1)),t(2*n,O::D){
		copy(a.begin(),a.end(),t.begin()+n);
		for(int i=n-1;i>0;--i)t[i]=O::uni(t[2*i],t[2*i+1]);
	}
	T query(int l,int r){
		T res=O::D;
		for(l+=n,r+=n;l<r;l/=2,r/=2){
			if(l&1)res=O::uni(res,t[l++]);
			if(r&1)res=O::uni(res,t[--r]);
		}
		return res;
	}
	void update(int p,T v){
		for(O::upd(t[p+=n],v);p/=2;)t[p]=O::uni(t[2*p],t[2*p+1]);
	}
};


struct maxq{
	typedef int T;
	static const T D;
	static T uni(T a,T b){return max(a,b);}
	static T upd(T&a,T b){return a=b;}
};
const maxq::T maxq::D = -1;

struct minq{
	typedef int T;
	static const T D;
	static T uni(T a,T b){return min(a,b);}
	static T upd(T&a,T b){return a=b;}
};
const minq::T minq::D = INT_MAX;


void ProGamerMove() {
	int n; cin >> n;
	vector<int> a(n), tmp(n, -1), ia(n);
	for (int& v : a) cin >> v, --v;
	for (int i = 0; i < n; ++i) ia[a[i]] = i;
	SparseTable<maxq> mx(a);
	SparseTable<minq> mn(a);
	ST<maxq> mxs(tmp);
	vector<vector<int>> g(n);
	function<void(int, int)> ae = [&] (int u, int v) {
//		cerr << u << ' ' << v << endl;
		g[u].push_back(v);
		g[v].push_back(u);
	};
	mxs.update(a[0], 0);
	for (int i = 1; i < n; ++i) {
		int bigger = mxs.query(a[i] + 1, n);
		int smaller = mxs.query(0, a[i]);
//		cerr << bigger << ' ' << smaller << endl;
		int pos = mn.query(bigger + 1, i + 1);
		ae(ia[pos], i);
		pos = mx.query(smaller + 1, i + 1);
		ae(ia[pos], i);
		mxs.update(a[i], i);
	}
	vector<int> vis(n);
	queue<int> q; q.push(0); vis[0] = 1;
	while (q.size()) {
		int u = q.front();
		q.pop();
		for (int v : g[u]) if (!vis[v]) {
			vis[v] = vis[u] + 1;
			q.push(v);
		}
	}
	cout << vis[n - 1] - 1 << '\n';
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}