#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())


template<class T,class U>
ostream& operator<<(ostream& os,const pair<T,U>& p){
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator <<(ostream& os,const vector<T>& v){
	os<<"{";
	for(int i = 0;i < (int)v.size(); i++){
		if(i)os<<",";
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
char s[N];
char c[N];
int main(){
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	// trace(n);
	if(n <= 3){
		printf("%c\n", s[1]);
		return 0;
	}
	int pos = 0;
	int i = 1, j = n;
	while(j - i + 1 >= 4){
		if(s[i] == s[j]){
			c[pos++] = s[i];
			i++;
			j--;
			continue;
		}
		if(s[i + 1] == s[j]){
			c[pos++] = s[i + 1];
			i+=2;
			j--;
			continue;
		}
		if(s[i] == s[j - 1]){
			c[pos++] = s[i];
			i++;
			j -= 2;
			continue;
		}
		c[pos++] = s[i + 1];
		i += 2;
		j -= 2;
	}
	int pos1 = pos;
	if(i != j){
		c[pos++] = s[i];
	}

	for(int i = pos1 - 1; i >= 0; i--) c[pos++] = c[i];

	printf("%s\n", ((string)c).c_str());
}