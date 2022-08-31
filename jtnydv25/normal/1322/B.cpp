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
const int N = 400005;
int a[N]; const int K = 25;
vector<int> val[30][2];
int main(){
	int n; sd(n);
	for(int i = 1; i <= n; i++){
		sd(a[i]);
		for(int k = 0; k < K; k++) val[k][a[i] >> k & 1].push_back(a[i] & ((1 << k) - 1));
	}
	ll ans = 0;
	for(int k = 0; k < K; k++){
		sort(all(val[k][0]));
		sort(all(val[k][1]));
		ll num = 0, num2 = 0;
		int V = 1 << k;
		int s0 = sz(val[k][0]);
		int s1 = sz(val[k][1]);
		for(auto it : val[k][0]){
			num += (upper_bound(all(val[k][1]), V - it - 1) - val[k][1].begin());
			num2 += s0 - (upper_bound(all(val[k][0]), V - it - 1) - val[k][0].begin());
			if(it + it >= V) num2--;
		}
		
		for(auto it : val[k][1]){
			num2 += s1 - (upper_bound(all(val[k][1]), V - it - 1) - val[k][1].begin());
			if(it + it >= V) num2--;
		}
		// if(n>2 && (num||num2))trace(k, num, num2, val[k][0], val[k][1]);
		ans += ((num + (num2 >> 1)) & 1) << k;
	}
	printf("%lld\n", ans);
}