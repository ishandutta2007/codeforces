#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<random>
#include<unistd.h>
//This code is written by Itst
using namespace std;

#define int long long
int read(){
	int a = 0; char c = getchar(); bool f = 0;
	while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){
		a = a * 10 + c - 48; c = getchar();
	}
	return f ? -a : a;
}

#define PII pair < int , int >
const int _ = 1e5 + 7 , MOD = 1e9 + 7;  
vector < int > ch[_]; PII stk[_][50];
int N , val[_] , top[_] , dep[_] , ans;

int gcd(int x , int y){return x == 0 || y == 0 ? x + y : __gcd(x , y);}

void dfs(int x , int p){
	dep[x] = dep[p] + 1;
	if(top[p]){
		int curd = stk[p][1].first , curgcd = gcd(stk[p][1].second , val[x]);
		stk[p][top[p] + 1] = PII(dep[x] , val[x]);
		for(int i = 2 ; i <= top[p] + 1 ; ++i){
			int g = gcd(stk[p][i].second , val[x]);
			if(g != curgcd){
				ans += (stk[p][i].first - curd) * curgcd % MOD;
				stk[x][++top[x]] = PII(curd , curgcd);
				curd = stk[p][i].first; curgcd = g;
			}
		}
		ans = (ans + (dep[x] - curd + 1) * curgcd) % MOD;
		stk[x][++top[x]] = PII(curd , curgcd);
	}
	else{ans = val[x] % MOD; stk[x][++top[x]] = PII(dep[x] , val[x]);}
	for(auto t : ch[x]) if(t != p) dfs(t , x);
}

signed main(){
	N = read(); for(int i = 1 ; i <= N ; ++i) val[i] = read();
	for(int i = 1 ; i < N ; ++i){
		int p = read() , q = read();
		ch[p].push_back(q); ch[q].push_back(p);
	}
	dfs(1 , 0); printf("%lld\n" , ans);
	return 0;
}