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
const int N = 500005;
int a[N];
int main(){
	int n, k; sd(n); sd(k);
	k = min(30, (k * 8)/ n);
	int mx = 0;
	int allowed = 1 << k;
	for(int i = 1; i <= n; i++) sd(a[i]);
	sort(a + 1, a + n + 1);
	int ind = 1;
	int ans = 1e9;
	int cnt = 0;
	// trace(k);
	multiset<int> present;
	for(int i = 1; i <= n; i++){
		// start at i
		if(i != 1){
			present.erase(present.find(a[i - 1]));
			if(present.find(a[i - 1]) == present.end() )
				cnt--;
		}
		while(ind <= n){
			if(present.find(a[ind]) == present.end()) cnt++;
			if(cnt > allowed){
				cnt--;
				break;
			}
			present.insert(a[ind]);
			ind++;
		}
		ans = min(ans, n - (ind - i));
		// trace(i, ind);
	}
	printf("%d\n", ans);
}