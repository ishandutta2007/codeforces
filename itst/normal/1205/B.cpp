#include<bits/stdc++.h>
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
const int _ = 1e5 + 3;
int val[_] , N , len = 1e9 , dis[_]; vector < int > pot[_];
vector < int > nxt[_]; int dep[_];

signed main(){
	N = read();
	for(int i = 1 ; i <= N ; ++i){
		val[i] = read();
		for(int j = 0 ; 1ll << j <= 1e18 ; ++j)
			if(val[i] >> j & 1) pot[j].push_back(i);
	}
	for(int i = 0 ; 1ll << i <= 1e18 ; ++i) if(pot[i].size() >= 3){puts("3"); return 0;}
	for(int i = 0 ; 1ll << i <= 1e18 ; ++i)
		if(pot[i].size() >= 2){
			nxt[pot[i][0]].push_back(pot[i][1]);
			nxt[pot[i][1]].push_back(pot[i][0]);
		}
	memset(dis , 0x3f , sizeof(dis));
	#define PII pair < int , int >
	for(int i = 1 ; i <= N ; ++i){
		sort(nxt[i].begin() , nxt[i].end());
		nxt[i].resize(unique(nxt[i].begin() , nxt[i].end()) - nxt[i].begin());
	}
	for(int i = 1 ; i <= N ; ++i){
		vector < int > mark; queue < PII > q; q.push(PII(i , 0)); dis[i] = 0; mark.push_back(i);
		while(!q.empty()){
			PII t = q.front(); q.pop();
			for(auto x : nxt[t.first])
				if(x != t.second)
					if(dis[x] > 1e9){dis[x] = dis[t.first] + 1; q.push(PII(x , t.first)); mark.push_back(x);}
					else len = min(len , dis[x] + dis[t.first] + 1);
		}
		for(auto t : mark) dis[t] = dis[0];
	}
	printf("%lld\n" , len == 1e9 ? -1 : len);
	return 0;
}