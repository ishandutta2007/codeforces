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

const int N = 100005;
int b[N], a[N];
int f[N], g[N], done[N];
vector<int> positions[N];

int main(){
	int t; sd(t);
	while(t--){
		int n, x, y; sd(n); sd(x); sd(y);
		for(int i = 0; i <= n + 1; i++){
			g[i] = f[i] = done[i] = 0;
			positions[i].clear();
		}
		int missing = 1;
		for(int i = 1; i <= n; i++){
			sd(b[i]);
			positions[b[i]].push_back(i);
			f[b[i]]++;
		}
		for(int i = 1; i <= n + 1; i++) if(f[i] == 0) missing = i;
		int lo = n, hi = 2 * n;
		while(lo < hi){
			int T = (lo + hi) >> 1;
			int sm = 0;
			for(int i = 1; i <= n + 1; i++){
				sm += min(f[i], T - f[i]);
			}
			if(sm >= y){
				hi = T;
			} else lo = T + 1; 
		}
		if(x < lo - n){
			printf("NO\n");
			continue;
		}

		int T = lo;
		int sm = 0;
		for(int i = 1; i <= n + 1; i++){
			sm += (g[i] = min(y - sm, min(f[i], T - f[i])));
		}

		g[missing] = n - sm;
		set<pii> st;
		set<pii> non_zero;
		set<pii> FF;
		set<pii> GG;

		for(int i = 1; i <= n + 1; i++){
			if(f[i] + g[i] > 0) st.insert({-f[i] - g[i], i});
			if(f[i] && g[i]){
				non_zero.insert({-f[i] - g[i], i});
			}
			if(f[i] > 0) FF.insert({-f[i], i});
			if(g[i] > 0) GG.insert({-g[i], i});
		}
		
		int rem = n;
		int cnt = 0;
		int xx = x;

		while(!st.empty()){
			auto it = st.begin();
			// MUST MATCH
			if(x > 0 || -it->F > rem){
				auto it2 = non_zero.begin();
				int c = it2->S;
				a[positions[c][done[c]++]] = c;
				cnt++;
				st.erase(*it2);
				FF.erase({-f[c], c});
				GG.erase({-g[c], c});
				g[c]--; f[c]--;

				non_zero.erase(it2);

				if(f[c] && g[c]){
					non_zero.insert({-f[c] - g[c], c});
				}
				if(f[c] + g[c] > 0) st.insert({-f[c] - g[c], c});
				if(f[c] > 0) FF.insert({-f[c], c});
				if(g[c] > 0) GG.insert({-g[c], c});
				x--;
			} else{
				// dont match
				int c1 = it->S;
				if(g[c1] == 0){
					c1 = GG.begin()->S;
				}
				auto it2 = FF.begin();
				int c2 = it2->S;
				if(c2 == c1){
					it2++;
					c2 = it2->S;
				}
				
				st.erase({-f[c1] - g[c1], c1});
				st.erase({-f[c2] - g[c2], c2});
				GG.erase({-g[c1], c1});
				FF.erase({-f[c2], c2});
				
				non_zero.erase({-f[c1] - g[c1], c1});
				non_zero.erase({-f[c2] - g[c2], c2});
				
				a[positions[c2][done[c2]++]] = c1;
				g[c1]--;
				f[c2]--;

				if(f[c1] + g[c1] > 0){
					st.insert({-f[c1] - g[c1], c1});
					if(f[c1] > 0 && g[c1] > 0){
						non_zero.insert({-f[c1] - g[c1], c1});
					}
				}

				if(f[c2] + g[c2] > 0){
					st.insert({-f[c2] - g[c2], c2});
					if(f[c2] > 0 && g[c2] > 0){
						non_zero.insert({-f[c2] - g[c2], c2});
					}
				}

				if(f[c2] > 0) FF.insert({-f[c2], c2});
				if(g[c1] > 0) GG.insert({-g[c1], c1});
			}
			rem--;
		}
		if(cnt != xx){
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for(int i = 1; i <= n; i++) printf("%d ", a[i]);
		printf("\n");
	}
}