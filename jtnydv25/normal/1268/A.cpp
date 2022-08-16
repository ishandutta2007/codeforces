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
const int N = 200005;
char s[N];
int a[N], b[N];
int main(){
	int n, k; sd(n); sd(k);
	scanf("%s", s);
	for(int i = 1; i <= n; i++) a[i] = s[i - 1] - '0';
	for(int i = 1; i <= k; i++) b[i] = a[i];
	for(int i = k + 1; i <= n; i++) b[i] = b[i - k];
	int ok = 1;
	for(int i = 1; i <= n; i++){
		if(a[i] > b[i]){
			ok = 0;
			break;
		}
		if(b[i] > a[i]) break;
	}
	if(ok){
		printf("%d\n", n);
		for(int i = 1; i <= n; i++) printf("%d", b[i]);
		return 0;
	}

	
	if(b[k] == 9){
		for(int j = k; j >= 1; j--){
			if(b[j] == 9) b[j] = 0;
			else{
				b[j]++;
				break;
			}
		}
	}
	else b[k]++;
	for(int i = k + 1; i <= n; i++) b[i] = b[i - k];
	printf("%d\n", n);
	for(int i = 1; i <= n; i++) printf("%d", b[i]);
	return 0;
}