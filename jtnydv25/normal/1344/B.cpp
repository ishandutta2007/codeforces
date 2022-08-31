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
const int N = 1 << 20;
char s[1 << 10][1 << 10];
int n, m;
int getIndex(int i, int j){
	return m * i + j;
}
int vis[N];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
int c[1 << 10], d[1 << 10];
void dfs(int node){
	vis[node] = 1;
	int i = node / m, j = node % m;
	for(int d = 0; d < 4; d++){
		int _i = i + dx[d], _j = j + dy[d];
		if(s[_i][_j] == '#' && min(_i, _j) >= 0 && _i < n && _j < m){
			int ind = getIndex(_i, _j);
			if(!vis[ind]) dfs(ind);
		}
	}
}

int main(){
	 sd(n); sd(m);
	for(int i = 0; i < n; i++){
		scanf("%s", s + i);
		int mx = -1, mn = m;
		int num = 0;
		for(int j = 0; j < m; j++){
			if(s[i][j] == '#'){
				mn = min(mn, j);
				mx = max(mx, j);
				num++;
			}
		}
		
		if(num == 0){
			c[i] = 1;
		}

		for(int j = mn + 1; j < mx; j++) if(s[i][j] == '.'){
			printf("-1\n");
			return 0;
		}
	}

	for(int j = 0; j < m; j++){
		int mx = -1, mn = n, num = 0;
		for(int i = 0; i < n; i++){
			if(s[i][j] == '#'){
				mn = min(mn, i);
				mx = max(mx, i);
				num++;
			}
		}
		if(num == 0){
			bool ok = false;
			for(int i = 0; i < n; i++) if(c[i]) ok = true;
			if(!ok){
				printf("-1\n");
				return 0;
			}
			d[j] = 1;
		}
		for(int i = mn + 1; i < mx; i++) if(s[i][j] == '.'){
			printf("-1\n");
			return 0;
		}
	}

	for(int i = 0; i < n; i++) if(c[i] == 1){
		bool ok = false;
		for(int j = 0; j < m; j++){
			if(d[j] == 1) ok = true;
		}
		if(!ok){
			printf("-1\n");
			return 0;
		}
	}

	int comp = 0;
	for(int i = 0; i < m * n; i++) if(s[i / m][i % m] == '#' && !vis[i]){
		comp++;
		dfs(i);
	}
	printf("%d\n", comp);
}