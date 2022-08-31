#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second

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

const int N = 1e6 + 10;
char a[N], b[N];
inline int f(int n){return n / 2 + (n & 1);}
int main(){
	int n;
	scanf("%d", &n);
	scanf("%s", a);
	scanf("%s", b);
	int ans = 0;
	for(int i = 0; i < n;){
		while(i < n && a[i] == b[i])i++;
		if(i==n)break;
		if(i == n - 1){
			ans++; break;
		}
		if(a[i + 1] == b[i + 1]){ans++; i+=2;}
		else{
			if(b[i] != b[i + 1]) ans++, i += 2;
			else ans ++, i++;
		}
	}
	printf("%d\n", ans);
}