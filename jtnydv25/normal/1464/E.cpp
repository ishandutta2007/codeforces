#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

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

template<class T>
ostream& operator <<(ostream& os,const set<T>& v){
	os<<"{";
	for(auto it = v.begin(); it != v.end(); it++){
		if(it != v.begin())os<<", ";
		os<<*it;
	}
	os<<"}";
	return os;
}

template<class T, class V>
ostream& operator <<(ostream& os,const map<T, V>& v){
	os<<"{";
	for(auto it = v.begin(); it != v.end(); it++){
		if(it != v.begin())os<<", ";
		os<<*it;
	}
	os<<"}";
	return os;
}

#ifdef LOCAL
#define cerr cout
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

void fwht(vector<int> & data, bool invert = false) {
	int dim = data.size();
    for (int len = 1; 2 * len <= dim; len <<= 1) {
        for (int i = 0; i < dim; i += 2 * len) {
            for (int j = 0; j < len; j++) {
                int a = data[i + j];
                int b = data[i + j + len];
                
                data[i + j] = add(a, b);
                data[i + j + len] = sub(a, b);
            }   
        }
    }
    if(invert){
        int invdim = inv(dim);
    	for(int i = 0; i < dim; i++) data[i] = mul(data[i], invdim);
    }
}

int mex(set<int> & s){
	for(int i = 0; ; i++) if(!s.count(i)) return i;
}
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int n, m; cin >> n >> m;
	vector<int> deg(n);
	vector<vector<int>> adj(n), rdj(n);
	vector<int> X(n);
	for(int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
		rdj[v].push_back(u);
		deg[u]++;
	}
	queue<int> q;
	for(int i = 0; i < n; i++) if(!deg[i]) q.push(i);
	int k = 0;
	while((1 << k) <= n) k++;
	vector<int> P(1 << k);
	vector<int> One(1 << k);
	One[0] = 1;
	P[0] = 1;
	int invT = inv(n + 1);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		set<int> st;
		for(int v : adj[u]) st.insert(X[v]);
		X[u] = mex(st);
		for(int v : rdj[u]){
			deg[v]--;
			if(deg[v] == 0) q.push(v);
		}
		P[X[u]] = sub(P[X[u]], invT);
	}
	
	fwht(One);
	fwht(P);
	// trace(One, P);
	vector<int> vals(1 << k);
	for(int i = 0; i < (1 << k);i++) vals[i] = mul(One[i], inv(P[i]));
	fwht(vals, true);
	// trace(vals);
	cout << sub(1, mul(invT, vals[0]));
}