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
const int N = 105;
int currx = 0, curry = 0, rice = 0, curr = 0;
int n, m;

void init(){
	currx = 0, curry = 0, rice = 0, curr = 0;
}
string str;
char ans[N][N];
char R[N][N];

void go(){
	ans[currx][curry] = str[curr];
	if(R[currx][curry] == 'R') rice++;
	if(curry %2 == 0){
		if(currx != n - 1) currx++;
		else curry++;
	} else{
		if(currx != 0) currx--;
		else curry++;
	}
}

int main(){
	for(char x = 'a'; x <= 'z'; x++) str += x;
	for(char x = 'A'; x <= 'Z'; x++) str += x;
	for(char x = '0'; x <= '9'; x++) str += x;
	int t; sd(t);
	while(t--){
		sd(n); sd(m); int k;
		sd(k);
		init();
		int total = 0;
		for(int i = 0; i < n; i++){
			scanf("%s", R[i]);
			for(int j = 0; j < m; j++) total += (R[i][j] == 'R');
		}
		vector<int> targets(k, total / k);
		for(int i = 0; i < (total % k); i++) targets[i]++;
		for(int i = 0; i < k; i++){
			while(rice < targets[i]) go();
			rice = 0;
			curr++;
		}
		curr--;
		while(currx < n && curry < m){
			go();
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++) printf("%c", ans[i][j]);
			printf("\n");
		}
	}
}