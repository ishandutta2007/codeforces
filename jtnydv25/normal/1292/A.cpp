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
int f[3][100005];
int main(){
	int n, q; sd(n); sd(q);
	int num = 0;
	// trace(n, q);
	while(q--){
		int r, c;
		sd(r); sd(c);
		r--; c--;
		// trace(r, c);
		for(int delta = -1; delta <= 1; delta++){
			int r2 = r^1;
			int c2 = c - delta;
			// trace(r2, c2);
			if(c2 >= 0 && c2 < n){
				int curr = f[r][c] & f[r2][c2];
				int nw = (f[r][c] ^ 1) & f[r2][c2];
				// trace(r, c, r2, c2, nw, curr);
				num += (nw - curr);
			}
		}
		f[r][c] ^= 1;
		printf(num == 0? "Yes\n" : "No\n");
	}
}