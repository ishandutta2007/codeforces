#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
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

inline int get(int n){
	int ret = 0;
	while(n != 1){
		n = __builtin_popcount(n);
		ret++;
	}
	return ret;
}
const int N = 2005;
int C[N][N];
int f[N];
const int mod = 1e9 + 7;
int main(){
	cin.tie(0);
	string s;
	for(int i = 0; i < N; i++){
		C[i][0] = 1;
		for(int j = 1; j <= i; j++){
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
			if(C[i][j] >= mod) C[i][j] -= mod;
		}
	}
	int k;
	cin >> s;
	cin >> k;
	if(k == 0){
		cout << 1;
		return 0;
	}

	int l = s.length();
	int cnt = 0;
	for(int i = 0; i < l; i++){
		if(s[i] == '1'){
			//l - i - 1
			int rem = l - i - 1;
			for(int j = 0; j <= rem; j++){
				f[cnt + j] += C[rem][j];
				if(f[cnt + j] >= mod) f[cnt + j] -= mod;
			}
			cnt++;
		}
	}
	f[1]--;
	f[cnt]++;		
	int ans = 0;
	for(int i = 1; i < N; i++){
		if(get(i) == k - 1) ans = (ans + f[i]) % mod;
	}
	cout << ans;
}