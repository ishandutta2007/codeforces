#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

struct rational{
	int num, den;
	rational(){}
	rational(int _num, int _den){
		num = _num; den = _den;
	}
	bool operator < (const rational & R)const{
		return num * 1ll * R.den < den * 1ll * R.num;
	}
};

#define T pair<rational, int>
#define ordered_set tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second


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
const int N =100005;
int cnt = 0;
vector<pii> neg, pos;
long long ans = 0;
ordered_set os1, os2;
int n, w;

int getless(ordered_set & os, rational R){
	return os.order_of_key({R, 0});
}

const int INF = 1e9;
int gethi(ordered_set & os, rational R){
	return os.size() - os.order_of_key({R, INF});
}

void process(vector<pii> & vec){
	int i = 0;
	os1.clear();
	os2.clear();
	while(i < vec.size()){
		int curr = i;
		int currx = vec[i].F;
		while(i < vec.size() && vec[i].F == currx) i++;
		// [curr, i - 1]
		for(int j = curr; j < i; j++){
			rational a = rational(currx, vec[j].S + w);
			rational b = rational(currx, vec[j].S - w);
			ans += curr - gethi(os1, a) - getless(os2, b);
		}

		for(int j = curr; j < i; j++){
			rational a = rational(currx, vec[j].S + w);
			rational b = rational(currx, vec[j].S - w);
			os1.insert({a, ++cnt});
			os2.insert({b, ++cnt});
		}
	}
}

int x[N], v[N];

int main(){
	sd(n); sd(w);
	for(int i = 1; i <= n; i++){
		sd(x[i]); sd(v[i]);
		if(x[i] < 0) neg.push_back({abs(x[i]), abs(v[i])});
		else pos.push_back({abs(x[i]), abs(v[i])});
	}
	sort(neg.begin(), neg.end());
	sort(pos.begin(), pos.end());
	process(neg);
	process(pos);
	os1.clear(); os2.clear();
	for(auto it : neg){
		os1.insert({rational(it.F, it.S + w), ++cnt});
		os2.insert({rational(it.F, it.S - w), ++cnt});
	}

	for(auto it : pos){
		rational a = rational(it.F, it.S + w);
		rational b = rational(it.F, it.S - w);
		ans += (int)neg.size() - gethi(os1, b) - getless(os2, a);
	}
	printf("%lld\n", ans);
}