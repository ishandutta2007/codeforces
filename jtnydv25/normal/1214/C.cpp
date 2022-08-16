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
const int N = 2e5 + 10;
char s[N];
int main(){
	int n; sd(n);
	scanf("%s", s + 1);
	
	string a = "(" + (string)(s + 1);

	if(2 * count(all(a), ')') != n) {
		printf("No\n");
		return 0;
	}
	
	int lst;
	for(int j = n; j >= 0; j--) if(a[j] == '('){
		lst = j;
		break;
	}
	// trace(lst);
	bool ok = true;
	int v = 0;
	for(int i = 0; i <= n; i++){
		if(i == lst) continue;
		v += 2 * (a[i] == '(') - 1;
		if(v < 0){
			ok = false;
		}
	}
	if(ok){
		printf("Yes\n");
		return 0;
	}

	string b = (string)(s + 1) + ")";
	int fst = 0;
	for(int i = 0; i <= n; i++) if(b[i] == ')'){
		fst = i;
		break;
	}

	v = 0;
	for(int i = 0; i <= n; i++){
		if(i == fst) continue;
		v += 2 * (b[i] == '(') - 1;
		if(v < 0){
			ok = false;
			break;
		}
	}

	if(ok){
		printf("Yes\n");
		return 0;
	}
	printf("No\n");
}