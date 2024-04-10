#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// views::zip, ranges::sort

typedef long long ll;
typedef long double ld;

struct ST{
	int n;vector<int>t;
	ST(vector<int>a):n(1<<int(log2(a.size())+1)),t(2*n,1e9){
		copy(a.begin(),a.end(),t.begin()+n);
		for(int i=n-1;i>0;--i)t[i]=min(t[2*i],t[2*i+1]);
	}
	int query(int l,int r){ l = max(0, l), r = min(n, r);
//		cerr << l << ' ' << r;
		int res=1e9;
		for(l+=n,r+=n;l<r;l/=2,r/=2){
			if(l&1)res=min(res,t[l++]);
			if(r&1)res=min(res,t[--r]);
		}
//		cerr << ' ' << res  << endl;
		return res;
	}
	void update(int p,int v){
//		cerr << "updating " << p << " to " << v << endl;
		for(t[p+=n] = v;p/=2;)t[p]=min(t[2*p],t[2*p+1]);
	}
};

void solve(vector<int> p, vector<int>& res) {
	int n = p.size();
	ST st(vector<int>(n, 1e9));
	priority_queue<pair<int, int>> rem;
	for (int i = 0; i < n; ++i) {
		res[i] = min(res[i], 1 + st.query(i - p[i], i));
		rem.push({-(i + p[i]), i});
		st.update(i, res[i]);
		while (rem.size() && rem.top().first == -i) {
			st.update(rem.top().second, 1e9);
			rem.pop();
		}
	}
}

void ProGamerMove() {
	int n, a, b; cin >> n >> a >> b, --a, --b;
	vector<int> p(n), res(n, 1e9);
	for (auto& v : p) cin >> v;
	res[a] = 0;
	for (int it = 0; it < 20; ++it) {
		solve(p, res);
//		for (int v : res) cerr << v << ' '; cerr << '\n';
		reverse(res.begin(), res.end());
		reverse(p.begin(), p.end());
	}
	cout << res[b] << "\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}