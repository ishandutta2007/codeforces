#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...) // remove in interactive
#define endl '\n'
#endif
const int mod = 998244353;
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (x * 1ll * y) % mod;}
inline int powr(int a, ll b){
	int x = 1 % mod;
	while(b){
		if(b & 1) x = mul(x, a);
		a = mul(a, a);
		b >>= 1;
	}
	return x;
}
inline int inv(int a){ return powr(a, mod - 2);}
const int N = 200000;
int p2[N];
int q2[N];

int getNum(vector<int> X, vector<int> Y, int k){
	// trace(X, Y, k);
	int ret = 0;
	if(k == 0){
		map<int, int> mapX, mapY;
		for(int x: X) mapX[x]++;
		for(int y: Y) mapY[y]++;
		for(auto it: mapX){
			ret = add(ret, mul(q2[it.second], q2[mapY[it.first]]));
		}
		return ret;
		// ret = add(ret, p2[sz(X)]);
		// ret = add(ret, p2[sz(Y)]);
		// return sub(ret, 1);
	}
	int b = __lg(k);
	vector<map<int, vector<int>>> U(2), V(2);
	set<int> possible;
	for(int a: X){
		int p = a >> b;
		int q = p & 1;
		p >>= 1;
		U[q][p].push_back(a & ((1 << b) - 1));
		possible.insert(p);
	}

	for(int a: Y){
		int p = a >> b;
		int q = p & 1;
		p >>= 1;
		V[q][p].push_back(a & ((1 << b) - 1));
		possible.insert(p);
	}
	for(int p: possible){
		auto itu0 = U[0].find(p), itu1 = U[1].find(p);
		auto itv0 = V[0].find(p), itv1 = V[1].find(p);
		int szu0 = (itu0 == U[0].end() ? 0 : sz(itu0->second));
		int szu1 = (itu1 == U[1].end() ? 0 : sz(itu1->second));

		int szv0 = (itv0 == V[0].end() ? 0 : sz(itv0->second));
		int szv1 = (itv1 == V[1].end() ? 0 : sz(itv1->second));

		int ways01 = (szu0 == 0 || szv1 == 0) ? 0 : getNum(itu0->second, itv1->second, k - (1 << b));
		int ways10 = (szu1 == 0 || szv0 == 0) ? 0 : getNum(itu1->second, itv0->second, k - (1 << b));

		// trace(ways01, szu0, szv1);
		ways01 = add(ways01, add(p2[szu0], p2[szv1]));
		ways01 = sub(ways01, 1);
		// trace(ways01);
		// trace(p, X, Y, k, ways01, ways10);

		ways10 = add(ways10, add(p2[szu1], p2[szv0]));
		ways10 = sub(ways10, 1);
		// trace(ways01, ways10, szu0, szv1);
		int ways = mul(ways01, ways10);
		ways = sub(ways, sub(add(p2[szu0 + szu1], p2[szv0 + szv1]), 1));
		ret = add(ret, ways);
	}
	return ret;
}

// int getNum2(vector<int> X, vector<int> Y, int k){
// 	int M = getNum(X, Y, k);
// 	trace(X, Y, k, M);
// 	return add(1, sub(M, add(p2[sz(X)], p2[sz(Y)])));
// }

int getNum(vector<int> X, int k){
	int ret = 0;
	if(k == 0){
		map<int, int> mapX;
		for(int x: X) mapX[x]++;
		for(auto it: mapX) ret = add(ret, q2[it.second]);
		return ret;
	}
	int b = __lg(k);
	vector<map<int, vector<int>>> U(2);
	set<int> possible;
	for(int a: X){
		int p = a >> b;
		int q = p & 1;
		p >>= 1;
		U[q][p].push_back(a & ((1 << b) - 1));
		possible.insert(p);
	}
	for(int p: possible){
		ret = add(ret, U[0].find(p) == U[0].end() ? 0 : q2[sz(U[0][p])]);
		ret = add(ret, U[1].find(p) == U[1].end() ? 0 : q2[sz(U[1][p])]);
		if(U[0].find(p) == U[0].end() || U[1].find(p) == U[1].end()) continue;
		// trace(p, U[0][p], U[1][p], ret, k, b);
		// trace(ret);
		ret = add(ret, getNum(U[0][p], U[1][p], k - (1 << b)));
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	p2[0] = 1;
	q2[0] = 0;
	for(int i = 1; i < N; i++){
		p2[i] = add(p2[i - 1], p2[i - 1]);
		q2[i] = p2[i] - 1;
	}
	int t = 1; 
	// cin >> t;
	while(t--){
		int n, k; cin >> n >> k;
		vector<int> a(n);
		for(int &x: a) cin >> x;
		cout << getNum(a, k) << endl;
	}
}