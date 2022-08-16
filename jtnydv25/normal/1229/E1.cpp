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

template<class T,class U>
ostream& operator<<(ostream& os,const map<T, U> & mp){
	os << "{";
	int i = 0;
	for(auto it : mp){
		if(i) os<<", ";
		os << it;
		i++;
	}
	os << "}";	
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

const int N = 6;
int p[N][N];

int mask[4];

const int mod = 1e9 + 7;

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
int P[6][1 << 6];
int valid[1 << 24];
int which[6];

inline int getInd(int i, int j){
	if(i > j) swap(i, j);
	return 4 * i + j - 1 - (i * (i - 1)) / 2;
}
int dp[1 << 15];
int ans = 0;
int num = 0;
void go(int i = 0){
	if(i == 4){
		vector<int> left;
		for(int j = 0; j < 6; j++){
			bool ok = 1;
			for(int k = 0; k < 4; k++) if(which[k] == j) ok = false;
			if(ok) left.push_back(j);
		}
		assert(sz(left) == 2);
		int ind = getInd(left[0], left[1]);
		for(int j = 0; j < 4; j++){
			mask[j] = 63;
			mask[j] ^= (1 << which[j]);
		}

		for(int m0 = mask[0]; ; m0 = mask[0] & (m0 - 1)){
			for(int m1 = mask[1]; ; m1 = mask[1] & (m1 - 1)){
				for(int m2 = mask[2]; ; m2 = mask[2] & (m2 - 1)){
					for(int m3 = mask[3]; ; m3 = mask[3] & (m3 - 1)){
						int M0 = (m0 ^ (1 << which[0]));
						int M1 = (m1 ^ (1 << which[1]));
						int M2 = (m2 ^ (1 << which[2]));
						int M3 = (m3 ^ (1 << which[3]));
						valid[(M0 << 18) + (M1 << 12) + (M2 << 6) + M3] |= (1 << ind);
						if(!m3) break;
					}
					if(!m2) break;
				}
				if(!m1) break;
			}
			if(!m0) break;
		}
		return;
	}
	for(int j = 0; j < 6; j++){
		bool ok = 1;
		for(int k = 0; k < i; k++) if(which[k] == j) ok = false;
		if(ok){
			which[i] = j;
			go(i + 1);
		}
	}
}


void go3(int i = 0){
	if(i == 4){
		int prob = 1;
		int msk = 0;
		for(int j = 0; j < 4; j++){
			prob = mul(prob, P[j][mask[j]]);
			msk |= (mask[j] << (6*(3 - j)));
		}
		ans = add(ans, mul(prob, dp[valid[msk]]));
		return;
	}
	for(int j = 0; j < 64; j++){
		mask[i] = j;
		go3(i + 1);
	}
}
void go2(int i = 4){
	if(i == 6){
		int total = 0;
		for(int a = 0; a < 6; a++){
			for(int b = 0; b < 6; b++) if(a != b && (mask[4] >> a & 1) && (mask[5] >> b & 1)){
				total |= (1<<getInd(a, b));
			}
		}
		int prob = mul(P[4][mask[4]], P[5][mask[5]]);
		for(int j = 0; j < (1 << 15); j++) if( (total & j) != 0) dp[j] = add(dp[j], prob);
		return;
	}
	for(int j = 0; j < 64; j++){
		mask[i] = j;
		go2(i + 1);
	}
}

int main(){
	int n;
	sd(n);

	for(int i = 0; i < n; i++) 
	for(int j = 0; j < n; j++){
		sd(p[i][j]);
		p[i][j] = mul(p[i][j], inv(100));
	}
	for(int k = n; k < 6; k++) p[k][k] = 1;

	n = 6;

	for(int i = 0; i < 6; i++)
		for(int j = 0; j < (1 << 6); j++){
			P[i][j] = 1;
			for(int k = 0; k < 6; k++){
				P[i][j] = mul(P[i][j], (j >> k & 1) ? p[i][k] : sub(1, p[i][k]));
			}
		}
	go();
	go2();
	go3();
	printf("%d\n", ans);
}