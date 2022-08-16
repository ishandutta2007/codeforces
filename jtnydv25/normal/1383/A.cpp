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

struct dsu{
    int n, comps;
    vector<int> par;
    dsu(int n) : n(n), par(n), comps(n){
        iota(par.begin(), par.end(), 0);
    }
    int root(int x){
        return x == par[x] ? x : (par[x] = root(par[x]));
    }
    bool merge(int x, int y){
        x = root(x); y = root(y);
        if(x == y) return 0;
        par[x] = y;
		comps--;
        return 1;
    }
};


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while(t--){
		int n; string A, B;
		cin >> n >> A >> B;
		bool ok = 1;
		dsu D(20);
		for(int i = 0; i < n; i++){
			if(A[i] > B[i]) ok = 0;
			else if(A[i] == B[i]) continue;
			else D.merge(A[i] - 'a', B[i] - 'a');
		}
		int ret = 20 - D.comps;
		if(!ok){
			ret = -1;
		}
		cout << ret << "\n";
	}
}