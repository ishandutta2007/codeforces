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

int get_log(int x){
	int r = 0; while((1 << r) < x) r++; return r;
}
const int N = 1 << 10;
int before[N];

bool done[N][N];

int n, k;
int cnt = 0;
bool cleared = 0;
char str[10];
bool ask(int x){
	cnt++;
	cleared = 0;
	printf("? %d\n", x);
	fflush(stdout);
	scanf("%s", str);
	return str[0] == 'Y';
}

void clear(){
	if(cleared) return;
	cleared = 1;
	printf("R\n");
	fflush(stdout);
}

void add(int block){
	for(int i = (block - 1) * k + 1; i <= block * k; i++) before[i] |= ask(i);
}

int num[N];
void dfs(int s){
	for(int i = s + 1; i <= n / k; i++){
		if(s == 0 && num[i] == n / k - i) continue;
		if(s != 0 && done[s][i]) continue;
		done[s][i] = 1;
		num[s]++;
		add(i);
		dfs(i);
	}
	clear();
	if(s != 0){
		dfs(0);
	}
}

int main(){
	sd(n); sd(k);
	k = max(1, k / 2);
	dfs(0);
	int ans = 0;
	for(int i = 1; i <= n; i++) ans += !before[i];
	printf("! %d\n", ans);
}