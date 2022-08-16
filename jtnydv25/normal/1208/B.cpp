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

const int N = 2005;
int a[N];
map<int, int> compress;
int freq[N][N];
set<int> st;
int main(){
	int n; sd(n);
	for(int i = 1; i <= n; i++){
		sd(a[i]);
		st.insert(a[i]);
	}
	int cnt = 0;
	for(auto it : st) compress[it] = ++cnt;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= cnt; j++) freq[j][i] = freq[j][i - 1];
		freq[compress[a[i]]][i]++;
	}	
	int ans = n;
	for(int i = 1; i <= n; i++){
		bool ok = true;
		for(int j = 1; j <= cnt; j++) if(freq[j][i - 1] >= 2){
			ok = false;
		}
		if(!ok) continue;
		int lo = i, hi = n + 1;
		while(lo < hi){
			int mid = (lo + hi) >> 1;
			ok = true;
			for(int j = 1; j <= cnt; j++){
				if(freq[j][i - 1] + freq[j][n] - freq[j][mid - 1] >= 2) ok = false;
			}
			if(ok) hi = mid;
			else lo = mid + 1;
		}
		ans = min(ans, lo - i);
	}
	printf("%d\n", ans);
}