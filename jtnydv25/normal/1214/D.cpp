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

const int N = 1000006;
int n, m;
char s[N];

inline int getInd(int x, int y){
	return x * m + y;
}

int reachable1[N], reachable2[N];
int dx1[2] = {0, 1};
int dx2[2] = {0, -1};

int dy1[2] = {1, 0};
int dy2[2] = {-1, 0};

void go(int * reachable, int * dx, int * dy, int y){
	queue<int> q;
	q.push(y);
	reachable[y] = 1;
	while(!q.empty()){
		int t = q.front();
		q.pop();
		int i = t / m, j = t % m;
		for(int dir = 0; dir < 2; dir++){
			int i1 = i + dx[dir];
			int j1 = j + dy[dir];
			int ind = getInd(i1, j1);
			if(i1 >= 0 && i1 < n && j1 >= 0 && j1 < m && s[ind] == '.' && !reachable[ind]){
				reachable[ind] = 1;
				q.push(ind);
			}
		}
	}
}

int main(){
	sd(n); sd(m);
	for(int i = 0; i < n; i++){
		scanf("%s", s + i * m);
	}
	go(reachable1, dx1, dy1, 0);
	if(!reachable1[getInd(n - 1, m - 1)]){
		printf("0\n");
		return 0;
	}

	go(reachable2, dx2, dy2, getInd(n - 1, m - 1));

	int ans = 2;
	for(int t = 1; t < n + m - 2; t++){
		int num = 0;
		for(int i = max(0, t - m + 1); i <= t && i < n; i++){
			int j = t - i;
			assert(j >= 0 && j < m);
			// if(j >= 0 && j < m){
				num += (reachable1[getInd(i, j)] & reachable2[getInd(i, j)]);
			// }
		}
		ans = min(ans, num);
	}	
	assert(ans > 0);
	printf("%d\n", ans);
}