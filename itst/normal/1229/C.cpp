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

const int _ = 1e5 + 7 , T = 2 * sqrt(_);
int N , M , Q , cnt , val[_] , big[_] , sml[_] , id[_] , d[_] , s[_] , t[_]; vector < int > nxt[_] , nxt2[_];
deque < int > bigger[T];

signed main(){
	N = read(); M = read();
	for(int i = 1 ; i <= N ; ++i) val[i] = i;
	for(int i = 1 ; i <= M ; ++i){s[i] = read(); t[i] = read(); ++d[s[i]]; ++d[t[i]];}
	for(int i = 1 ; i <= M ; ++i){
		if(d[s[i]] >= T && d[t[i]] >= T){nxt2[s[i]].push_back(t[i]); nxt2[t[i]].push_back(s[i]);}
		nxt[t[i]].push_back(s[i]); nxt[s[i]].push_back(t[i]);
	}
	for(int i = 1 ; i <= N ; ++i)
		if(d[i] >= T){
			id[i] = ++cnt;
			for(auto p : nxt[i]) if(p > i && d[p] < T) bigger[cnt].push_back(p);
		}
	int ans = 0;
	for(int i = 1 ; i <= N ; ++i){
		for(auto t : nxt[i]) t < i ? ++sml[i] : ++big[i];
		ans += big[i] * sml[i];
	}
	printf("%lld\n" , ans); Q = read();
	for(int i = 1 ; i <= Q ; ++i){
		int x = read(); ans -= big[x] * sml[x]; sml[x] = nxt[x].size(); big[x] = 0;
		if(d[x] < T){
			for(auto p : nxt[x])
				if(val[p] > val[x]){
					ans -= sml[p] * big[p]; ans += (--sml[p]) * (++big[p]);
					if(d[p] >= T) bigger[id[p]].push_back(x);
				}
		}
		else{
			while(!bigger[id[x]].empty()){
				int p = bigger[id[x]].front(); bigger[id[x]].pop_front();
				ans -= sml[p] * big[p]; ans += (--sml[p]) * (++big[p]);
			}
			for(auto p : nxt2[x]) if(val[p] > val[x]){ans -= sml[p] * big[p]; ans += (--sml[p]) * (++big[p]);}
		}
		val[x] = N + i; printf("%lld\n" , ans);
	}
	return 0;
}