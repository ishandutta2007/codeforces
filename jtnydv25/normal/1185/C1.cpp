#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second
#define all(c) ((c).begin()), ((c).end())


#ifdef LOCAL
#define cerr cout
#else
#endif

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

int main(){
	int n, m;
	sd(n); sd(m);
	multiset<int> st;
	for(int i = 1; i <= n; i++){
		int x;
		sd(x);
		auto it = st.begin();
		int num = 0;
		int sm = 0;
		int mx = m - x;
		while(it != st.end()){
			if(sm + *it > mx) break;
			num++;
			sm += *it;
			it++;
		}
		printf("%d ", i - 1 - num);
		st.insert(x);
	}
}