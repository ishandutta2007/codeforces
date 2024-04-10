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

int main(){
	string s;
	cin >> s;
	int na = 0, nb = 0, lst = -1;
	int n = s.length();
	int fst = n;	
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++)
			if(s[i] > s[j]){
				cout << "NO";
				return 0;
			}
	}
	for(int i = 0; i < n; i++){
		if(s[i] != 'c') lst = i;
		if(fst == n && s[i] == 'c') fst = i;
		if(s[i] == 'a') na++;
		if(s[i] == 'b') nb++;
	}
	int nc = n - 1 - lst;
	cout << ((na!=0 && nb!=0 && lst < fst && (nc == na||nc==nb)) ? "YES\n":"NO\n");

}