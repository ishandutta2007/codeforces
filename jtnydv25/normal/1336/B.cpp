#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%lld", &(x))
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
#define int ll
main(){
	int t; sd(t);
	while(t--){
	int n = 3;
    vector<vector<int>> vec(n);
    map<int, vector<pii>> changes;
    int sm = 0;
	vector<int> sizes(3);
	for(int i = 0; i < 3; i++) sd(sizes[i]);
	
    for(int i = 0; i < n; i++){
		int k = sizes[i];
        vec[i].resize(sizes[i]);
        for(int j = 0; j < k; j++){
            int x; sd(vec[i][j]);
        }
        sort(all(vec[i]));
        for(int j = 1; j < k; j++){
            changes[vec[i][j] + vec[i][j - 1]].push_back({i, vec[i][j]});
        }
    }
    vector<int> curr(n);
    ll sm_x = 0, sm_x2 = 0;
    for(int i = 0; i < n; i++){
        curr[i] = vec[i][0];
        sm_x += curr[i];
        sm_x2 += curr[i] * (ll) curr[i];
    }
    ll ans = n * sm_x2 - sm_x * sm_x;
    int num = 0;
    for(auto it : changes){
        num++;
        vector<pii> updates = it.S;
        for(auto it2 : updates){
            sm_x += it2.S - curr[it2.F];
            sm_x2 += (it2.S) * (ll) it2.S - (curr[it2.F] * (ll) curr[it2.F]);
            curr[it2.F] = it2.S;
        }
        ans = min(ans, n * sm_x2 - sm_x * sm_x);
    }
    printf("%lld\n", ans);
	}
}