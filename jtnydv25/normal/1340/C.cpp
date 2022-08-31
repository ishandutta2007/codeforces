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

const int N = 10005;
int d[N];
const int M = 1024 * 10006;
int dist[M];
const int INF = 1 << 30;
int main(){
	int n, m; sd(n); sd(m); 
	for(int i = 1; i <= m; i++) sd(d[i]);
	sort(d + 1, d + m + 1);
	d[m + 1] = n;
	deque<int> Q;
	fill(dist, dist + M, INF);
	Q.push_front(0);
	dist[0] = 0;
	ll ans = 1LL << 60;
	int g, r; sd(g); sd(r);
	while(!Q.empty()){
		int u = Q.front(); Q.pop_front();
		int pos = u >> 10;
		int phase = u & 1023;
		ll curr = dist[u] * (ll) (g + r) + phase;
		int rem = g - phase;
		if(pos != m + 1){
			// go right
			if(d[pos + 1] - d[pos] <= rem){
				int new_phase = phase + d[pos + 1] - d[pos], cost = 0;
				if(new_phase >= g){
					new_phase -= g;
					cost = 1;
				}
				int mask = ((pos + 1) << 10) + new_phase;
				if(dist[mask] <= dist[u] + cost) continue;
				dist[mask] = dist[u] + cost;
				if(pos + 1 == m) ans = min(ans, curr + d[pos + 1] - d[pos]);
				if(cost == 0) Q.push_front(mask);
				else Q.push_back(mask);
			}
		}

		if(pos > 1){
			if(d[pos] - d[pos - 1] <= rem){
				int new_phase = phase + d[pos] - d[pos - 1], cost = 0;
				if(new_phase >= g){
					new_phase -= g;
					cost = 1;
				}
				int mask = ((pos - 1) << 10) + new_phase;
				if(dist[mask] <= dist[u] + cost) continue;
				dist[mask] = dist[u] + cost;
				if(cost == 0) Q.push_front(mask);
				else Q.push_back(mask);
			}
		}
	}
	if(ans == (1LL << 60)) printf("-1\n");
	else printf("%lld\n", ans);
}