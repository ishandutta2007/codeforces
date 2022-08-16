#include <bits/stdc++.h>
using namespace std;

#define ll long long
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

template<class T>
ostream& operator <<(ostream& os,const multiset<T>& v){
	os<<"{";
	auto it = v.begin();
	while(it != v.end()){
		os<<*it << " ";
		it++;
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

const int N = 4005;
int x[N], y[N];
void fix(vector<int> & v){
	sort(all(v), [&](int i, int j){return x[i] < x[j];});
	while(sz(v) >= 2){
		bool bad = false;
		for(int i = sz(v) - 2; i >= 0; i--){
			if(y[v[i]] <= y[v[i + 1]]){
				bad = true;
				v.erase(v.begin() + i);
				break;
			}
			if(x[v[i]] == x[v[i + 1]]){
				bad = true;
				v.erase(v.begin() + i + 1);
				break;
			}
		}
		if(!bad) break;
	}
}
const int M = 1000006;
vector<int> updates[M];
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n + m; i++) cin >> x[i] >> y[i];
	vector<int> a(n), b(m);
	iota(all(a), 0);
	iota(all(b), n);
	fix(a);
	fix(b);
	vector<int> ptr(n, -1);
	vector<int> vals(n, 0);
	multiset<int> st;
	for(int i : a) for(int r = 0; r < sz(b); r++){
		int j = b[r];
		if(x[j] >= x[i]){
			updates[x[j] - x[i] + 1].push_back(i);
			if(ptr[i] == -1){
				ptr[i] = r;
				vals[i] = max(0, y[j] - y[i] + 1);
			}
		}
	}
	for(int i : a) st.insert(vals[i]);
	int ans = *st.rbegin();
	for(int X = 1; X < M; X++){
		for(int i : updates[X]){
			st.erase(st.find(vals[i]));
			if(ptr[i] + 1 < sz(b)){
				ptr[i]++;
				vals[i] = max(0, y[b[ptr[i]]] - y[i] + 1);
			} else vals[i] = 0;
			st.insert(vals[i]);
		}
		// if(!updates[X].empty()) trace(X, vals, st);
		ans = min(ans, X + *st.rbegin());
	}
	cout << ans << endl;
}