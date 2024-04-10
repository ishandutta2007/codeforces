#include<bits/stdc++.h>
#define ld long double
#define MAXN 500010
#define int long long
using namespace std;

inline int read(){
	int a = 0;
	bool f = 0;
	char c = getchar();
	while(!isdigit(c)){
		if(c == '-')
			f = 1;
		c = getchar();
	}
	while(isdigit(c)){
		a = (a << 3) + (a << 1) + (c ^ '0');
		c = getchar();
	}
	return f ? -a : a;
}

struct Edge{
	int end , upEd , w;
}Ed[MAXN];
int head[MAXN] , siz[MAXN] , T[MAXN] , N , cntEd , forC;
ld dp[MAXN];

bool cmp(int a , int b){
	return T[a] * siz[b] < T[b] * siz[a];
}

inline void addEd(int a , int b , int c){
	Ed[++cntEd].end = b;
	Ed[cntEd].upEd = head[a];
	Ed[cntEd].w = c;
	head[a] = cntEd;
}

void dfs(int now){
	siz[now] = 1;
	vector < int > v;
	for(int i = head[now] ; i ; i = Ed[i].upEd)
		if(!siz[Ed[i].end]){
			dfs(Ed[i].end);
			siz[now] += siz[Ed[i].end];
			T[Ed[i].end] += Ed[i].w << 1;
			dp[Ed[i].end] += Ed[i].w * siz[Ed[i].end];
			v.push_back(Ed[i].end);
		}
	sort(v.begin() , v.end() , cmp);
	for(int i = 0 ; i < v.size() ; i++){
		dp[now] += T[now] * siz[v[i]] + dp[v[i]];
		T[now] += T[v[i]];
	}
}
main(){
	N = read();
	for(int i = 1 ; i < N ; i++){
		int a = read() , b = read() , c = read();
		addEd(a , b , c);
		addEd(b , a , c);
	}
	dfs(1);
	cout << fixed << setprecision(8) << dp[1] * 1.0 / (N - 1);
	return 0;
}