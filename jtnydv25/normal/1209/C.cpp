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
const int N = 200005;
char s[N];
char type[N];
char concat[N];
bool ok(int n){
	int ind = 0;
	for(int i = 0; i < n; i++) if(type[i] == '1') concat[ind++] = s[i];
	for(int i = 0; i < n; i++) if(type[i] == '2') concat[ind++] = s[i];
	assert(ind == n);
	for(int i = 0; i + 1 < n; i++) if(concat[i] > concat[i + 1]) return 0;
	return 1;
}

int main(){
	int t; sd(t);
	while(t--){
		int n; sd(n);
		scanf("%s", s);
		bool done = false;
		for(int d = 0; d <= 9; d++){
			int lst = -1;
			for(int i = 0; i < n; i++) type[i] = '2';
			for(int i = 0; i < n; i++) if(s[i] - '0' < d){
				type[i] = '1';
				lst = i;
			}
			for(int j = lst + 1; j < n; j++) if(s[j] - '0' == d) type[j] = '1';
			// trace(d);
			// printf("%s\n", ((string)type).c_str());
			if(ok(n)){
				type[n] = 0;
				printf("%s", ((string)type).c_str());
				printf("\n");
				done = true;
				break;
			}
		}
		// return 0;
		if(done) continue;
		printf("-\n");
	}
}