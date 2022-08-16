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

const int N = 1005;
char s[N][N];
int n;
void invert(){
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++){
			if(i != j){
				if(s[i][j] == '0') s[i][j] = '1';
				else s[i][j] = '0';
			}
		}
}

void init(){
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++){
			s[i][j] = '0';
		}
}

void print(){
	for(int i = 1; i <= n;i++) printf("%s\n", s[i] + 1/*.c_str()*/);
}

void make(int c){
	for(int i = c; i < n; i++) s[i][i+1] = s[i+1][i] = '1';
}

int main(){
	int a, b; sd(n); sd(a); sd(b);
	if(min(a, b) != 1){
		printf("NO\n");
		return 0;
	}

	init();

	if(a == 1 && b == 1){
		if(n == 2 || n == 3){
			printf("NO\n");
			return 0;
		}
	}

	make(max(a, b));
	if(a == 1) invert();
	printf("YES\n");
	print();
}