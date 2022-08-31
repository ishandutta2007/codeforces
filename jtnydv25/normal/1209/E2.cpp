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
const int N = 2005;
const int M = (1 << 12);
int a[12][N];
int dp[M];
bool ok[N];
const int INF = 1e9;
int val[M], val2[M];
int main(){
	int t=40;
	sd(t);
	while(t--){
		int n=12, m=2000;
		sd(n); sd(m);
		for(int i = 0; i < n; i++)
			for(int j = 1; j <= m; j++){
				a[i][j] = rand()%100000;
				sd(a[i][j]);
			}
		memset(ok, 0, sizeof ok);
		for(int i = 0; i < (1 << n); i++) dp[i] = -INF;
		
		dp[0] = 0;
		vector<int> pos(m);
		iota(all(pos), 1);
		
		for(int i = 1; i <= m; i++){
			val[i] = 0;
			for(int j = 0; j < n; j++) val[i] = max(val[i], a[j][i]);
		}

		sort(all(pos), [&](int i, int j){return val[i] > val[j];});
		for(int j = 0; j < n && j < m; j++) ok[pos[j]] = 1;
		for(int j = 1; j <= m; j++){
			if(!ok[j]){
				continue;
			}
			for(int T = 0; T < (1<<n); T++){
				val[T] = 0;
				for(int k = 0; k < n; k++) if(T >> k & 1){
					val[T] += a[k][j];
				}
			}
				
			for(int T = 0; T < (1 << n); T++){
				val2[T] = 0;
				for(int shift = 0; shift < n; shift++){
					int msk = 0;
					for(int k = 0; k < n; k++) if(T >> k & 1) msk |= (1 << ((k + shift) % n));
					val2[T] = max(val2[T], val[msk]);
				}
			}
			for(int now = (1<<n) - 1; now >= 0; now--){
				for(int old = now; old; old = (old - 1) & now){
					dp[now] = max(dp[now], dp[old] + val2[old ^ now]);
				}
				dp[now] = max(dp[now], val2[now]);
			}
		}

		printf("%d\n", dp[(1<<n)-1]);
	}
}