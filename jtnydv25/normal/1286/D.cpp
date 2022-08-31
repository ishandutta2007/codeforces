#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())
#define ld long double

template<class T,class U>
ostream& operator<<(ostream& os,const pair<T,U>& p){
	os<<"("<<p.first<<", "<<p.second<<")";
	return os;
}

template<class T>
ostream& operator <<(ostream& os,const vector<T>& v){
	os<<"{";
	for(int i = 0;i < (int)v.size(); i++){
		if(i)os<<", ";
		os<<v[i];
	}
	os<<"}";
	return os;
}

#ifdef LOCAL
#define cerr cout
#else
#endif

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

struct Data{
	int ways[2][2];
	Data(){memset(ways, 0, sizeof ways);}
};
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

const int N = 200005;
Data T[N << 2];
int p[N][2];

int cond[N];

Data merge(const Data & P, const Data & Q, int mid){
	// mid, mid + 1
	int t = cond[mid];
	int right_left_banned = t >> 0 & 1;
	int right_right_banned = t >> 1 & 1;
	int left_left_banned = t >> 2 & 1;
	Data ret;
	for(int j = 0; j < 2; j++){
		for(int k = 0; k < 2; k++){
			if(right_left_banned && j && !k) continue;
			if(right_right_banned && j && k) continue;
			if(left_left_banned && !j && !k) continue;
			for(int i = 0; i < 2; i++){
				for(int l = 0; l < 2; l++){
					ret.ways[i][l] = add(ret.ways[i][l], mul(P.ways[i][j], Q.ways[k][l]));
					// trace(i, j, k, l, ret.ways[i][l]);
				}
			}
		}
	}
	return ret;
}

void make(int s, int e, int ind = 1){
	if(s == e){
		for(int d = 0; d < 2; d++) T[ind].ways[d][d] = p[s][d];
		return;
	}
	int mid = (s + e) >> 1;
	make(s, mid, ind << 1);
	make(mid + 1, e, ind << 1 | 1);
	T[ind] = merge(T[ind << 1], T[ind << 1 | 1], mid);
}

void update(int i, int s, int e, int ind = 1){
	if(s == e) return;
	int mid = (s + e) >> 1;
	if(i <= mid) update(i, s, mid, ind << 1);
	else update(i, mid + 1, e, ind << 1 | 1);
	T[ind] = merge(T[ind << 1], T[ind << 1 | 1], mid);
}

int getAns(){
	int ret = 0;
	for(int i = 0; i < 2; i++)	for(int j = 0; j < 2; j++) ret = add(ret, T[1].ways[i][j]);
	return ret;
}

int x[N], v[N];
vector<pii> vec;

int main(){
	int n; sd(n);
	for(int i = 1; i <= n; i++){
		sd(x[i]); sd(v[i]); sd(p[i][1]);
		p[i][1] = mul(p[i][1], inv(100));
		p[i][0] = sub(1, p[i][1]);
	}
	for(int i = 1; i < n; i++){
		// opposite
		vec.push_back({i, 0});
		if(v[i] > v[i + 1]) vec.push_back({i, 1});
		else if(v[i] < v[i + 1]) vec.push_back({i, 2});
	}

	sort(all(vec), [&](const pii & X, const pii & Y){
		int i = X.F, j = Y.F;
		int t1 = X.S, t2 = Y.S;
		int d1 = x[i + 1] - x[i];
		int d2 = x[j + 1] - x[j];
		int vel_1 = t1 == 0 ? v[i] + v[i + 1] : abs(v[i] - v[i + 1]);
		int vel_2 = t2 == 0 ? v[j] + v[j + 1] : abs(v[j] - v[j + 1]);
		return (d1 * (ll) vel_2) < (d2 * (ll) vel_1);
	});

	make(1, n);
	int currProb = getAns();
	int ans = 0;
	for(auto it : vec){
		int i = it.F, type = it.S;
		int D = x[i + 1] - x[i];
		int V = type == 0 ? v[i] + v[i + 1] : abs(v[i] - v[i + 1]);
		// if(n == 4){
		// 	trace(D / (double)V);
		// }
		cond[i] |= (1 << type);
		update(i, 1, n);
		int newProb = getAns();
		ans = add(ans, mul(sub(currProb, newProb), mul(D, inv(V))));
		currProb = newProb;
	}
	printf("%d\n", ans);
}