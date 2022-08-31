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
const int N = 200005;
int partner[N];
char inp[N], out[N];
void go(int i, int j, int pos1, int pos2){
	int n = j - i + 1, k = pos2 - pos1 + 1;
	if(!k) return;
	if(partner[i] == j){
		out[pos1] = '('; out[pos2] = ')';
		go(i + 1, j - 1, pos1 + 1, pos2 - 1);
	} else{
		int pos = partner[i];
		if(pos - i + 1 >= k){
			go(i, pos, pos1, pos2);
		} else{
			for(int k = i; k <= pos; k++) out[pos1++] = inp[k];
			go(pos + 1, j, pos1, pos2);
		}
	}
}
vector<int> st;
int main(){
	int n, k; sd(n); sd(k);
	scanf("%s", inp);
	for(int i = 0; i  < n; i++){
		if(inp[i] == ')'){
			partner[st.back()] = i;
			st.pop_back();
		} else st.push_back(i);
	}
	go(0, n - 1, 0, k - 1);
	printf("%s\n", out);
}