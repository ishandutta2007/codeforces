#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define DMAX 
#define INF (1LL << 62) 
#define MMAX 

using namespace std;

long long n, k, x, q, c[510], final, init, p, w;
string s;
vector <long long> states, dp1;
long long state_nr[10240];
map<long, long> m;
vector <pair<long long, long long> > v;

long long bitcnt(long long k) {
	long long ans = 0;
	while(k) {
		if(k % 2) ans++;
		k/=2;
	}
	return ans;
}

class matrix {
public:

	long long n;
	long long v[107][107];

	matrix() {for(long long i = 0; i < 100; i++) for(long long j = 0; j < 100; j++) v[i][j] = INF;}
	matrix(long long _n) {n = _n; for(long long i = 0; i < n; i++) for(long long j = 0; j < n; j++) v[i][j] = INF;}
	
	vector <long long> operator *(vector <long long> e) {
		vector <long long> ans(n, INF);
		for(long long i = 0; i < n; i++)
			for(long long j = 0; j < n; j++)
				if(e[i] != INF && v[i][j] != INF && ans[j] > e[i] + v[i][j])
					ans[j] = e[i] + v[i][j];
		return ans;
	} 

	void dbg_mat() {
		for(long long i = 0; i < n; i++){
			for(long long j = 0; j < n; j++)
				if(v[i][j] != INF) cerr << v[i][j] << ' ';
				else cerr << "X ";
			cerr << '\n';
		}
	}

	matrix operator *(matrix m) {
		matrix ans(n);
		for(long long i = 0; i < n; i++)
			for(long long j = 0; j < n; j++)
				for(long long k = 0; k < n; k++) 
					if(v[i][k] != INF && m.v[k][j] != INF && ans.v[i][j] > v[i][k] + m.v[k][j])
						ans.v[i][j] = v[i][k] + m.v[k][j];
		return ans;
	}
};

matrix pow(matrix base, long long exp) {
	if(exp == 1) return base;

	matrix a = pow(base, exp / 2);
	a = a * a;
	if(exp % 2) a = a * base;
	return a;
}

template<class T>
ostream& operator<<(ostream& out, vector<T> v) { 
	out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out; }


long long next_state(long long state, long long mov) {

	long long i = 0;
	while((state & (1 << i)) == 0) i++;
	
	if((i + mov > k) || (state & (1 << (mov + i))) != 0) 
		return INF;
 	
	state = (state + (1 << (mov + i))) / 2;
	if(i >= 1) state ^= (1 << (i - 1));
	
	return state;
}

long long next_static_state(long long state, long long mov) {

	long long i = 0;
	while((state & (1 << i)) == 0) i++;
	
	if((i + mov >= k) || (state & (1 << (mov + i))) != 0) 
		return INF;
 	
	state = (state + (1 << (mov + i)));
	state ^= (1 << i);
	
	return state;
}

long long lsb(long long k) {
	long long i = 0;
	while((k & (1 << i)) == 0) i++;
	return i;
}

bool cmp(long long a, long long b) {
	while(a % 2 == b % 2) a /= 2, b /= 2;
	if(a % 2) return true;
	return false;
}

vector <long long> init_cost() {
	vector <long long> ans(states.size(), INF); 
	ans[0] = 0;

	for(long long i = 0; i < states.size(); i++) {
		if(ans[i] == INF) continue;

		for(long long j = 1; j <= k; j++) {
			long long stf = next_static_state(states[i], j), cst = c[j];
			
			if(m.count(1 + j + lsb(states[i]))) 
				cst += m[1 + j + lsb(states[i])];

			if(stf != INF && ans[state_nr[stf]] > ans[i] + cst)
				ans[state_nr[stf]] = cst + ans[i];
		}
	}
	return ans;
}


void adv(vector <long long> &dp, long long cpos) {
	vector <long long> ans(states.size(), INF);
	for(long long i = 0; i < states.size(); i++) {
		if(dp[i] == INF) continue;

		if(states[i] % 2 == 0) ans[state_nr[states[i] / 2]] = min(dp[i], ans[state_nr[states[i] / 2]]);

		for(long long j = 1; j <= k; j++) {
			long long stf = next_state(states[i], j), cst = c[j];
			
			if(m.count(cpos + j + lsb(states[i]))) 
				cst += m[cpos + j + lsb(states[i])];

			if(stf != INF && (ans[state_nr[stf]] > dp[i] + cst)) 
				ans[state_nr[stf]] = cst + dp[i];
		}
	}
	// dbg(ans);
	dp = ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> x >> k >> n >> q;

	for(long long i = 0; i < (1 << k); i++)
		if(bitcnt(i) == x) states.push_back(i);
	
	sort(states.begin(), states.end(), cmp);

	for(long long i = 0; i < states.size(); i++)
		state_nr[states[i]] = i;

	for(long long i = 1; i <= k; i++) cin >> c[i];

	matrix one(states.size());
	for(long long i = 0; i < states.size(); i++) {

		if(states[i] % 2 == 0) one.v[i][state_nr[states[i] / 2]] = 0LL;//min(0LL, one.v[i][state_nr[states[i] / 2]]);
		
		for(long long j = 1; j <= k; j++) {
			long long stf = next_state(states[i], j);
			if(stf != INF)
				one.v[i][state_nr[stf]] = min(c[j], one.v[i][state_nr[stf]]);
		}
	}

	// dbg(states);

	for(long long i = 1; i <= q; i++) {
		cin >> p >> w; m[p] = w;
		v.push_back({p, w});
	}

	v.push_back({n + 1, 0});
	sort(v.begin(), v.end());
	
	dp1 = init_cost();
	// dbg(dp1);
	
	long long pos = 1;
	for(long long i = 0; i < v.size(); i++) {
		long long to = max(min(v[i].first, n - k + 1), pos);
		if(pos < to - k) dp1 = pow(one, to - k - pos) * dp1, pos = to - k;//, dbg(i);
		for(;pos < to; pos++) adv(dp1, pos);
	}
	// dbg(pos);
	// dbg(dp1);
	// cout << dp1.back() << '\n';
	for(;pos < n - x + 1; pos++) adv(dp1, pos);
	cout << dp1[0] << '\n';
	
	/*
	for(int i = 0; i <= n - x; i++)
		adv(dp1, i);
	cout << dp1[0] << '\n';*/


}