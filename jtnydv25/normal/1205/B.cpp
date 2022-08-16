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

const int N = 100005;

ll a[N];
vector<int> pos[64];

vector<int> con[140];
const int INF = 1e9;
int go(int i, int j, int n){
	queue<int> q;
	vector<int> dist(n, INF);
	q.push(i);
	dist[i] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v : con[u]) if(!(u == i && v == j) && dist[v] == INF){
			q.push(v);
			dist[v] = dist[u] + 1;
		}
	}
	// trace(i, j, dist[j]);
	return dist[j] + 1;
}

int main(){
	vector<int> vec;
	int n; sd(n);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
		for(int j = 0; j < 61; j++) if(a[i] >> j & 1) pos[j].push_back(i);
	}

	for(int i = 0; i < 64; i++){
		if(sz(pos[i]) >= 3){
		printf("3\n");
		return 0;
		}
	}
	set<int> indices;
	for(int j = 0; j < 64; j++) if(sz(pos[j]) == 2){
		for(auto it : pos[j]) indices.insert(it);
	}
	// trace(indices);
	vector<int> V;
	for(auto it : indices) V.push_back(it);
	// trace(V);
	int _n = sz(V);

	for(int j = 0; j < _n; j++) 
	for(int k = 0; k < j; k++)if(a[V[j]] & a[V[k]]){
		con[j].push_back(k);
		con[k].push_back(j);
	}
	int ans = INF;
	for(int j = 0; j < _n; j++) 
	for(int k = 0; k < j; k++)if(a[V[j]] & a[V[k]]){
		ans = min(ans, go(j, k, _n));
	}
	if(ans == INF) ans = -1;
	printf("%d\n", ans);
}