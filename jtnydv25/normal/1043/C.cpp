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
int f[100000];
int main(){
	string s;
	cin.tie(0);
	cin >> s;
	vector<int> vec;
	for(int i = 0; i < s.length(); ){
		if(s[i] == 'a'){
			while(i < s.length() && s[i] == 'a') i++;
			int pos = i - 1;
			while(i < s.length() && s[i] == 'b') i++;
			vec.push_back(pos);
			if(i != s.length()) vec.push_back(i - 1);
		} else{
			while(i < s.length() && s[i] == 'b') i++;
			int pos = i - 1;
			int cnta = 0;
			while(i < s.length() && s[i] == 'a') i++, cnta++;
			if(cnta != 0){
				vec.push_back(pos);
				vec.push_back(i - 1);
			}
		}
	}
	
	for(auto it : vec) f[it] = 1;
		for(int i = 0; i < s.length(); i++) printf("%d ", f[i]);

}