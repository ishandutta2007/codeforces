#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); bool f = 0; while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return f ? -a : a;
}

const int _ = 203; int N , M , s[2003] , t[2003] , tp[2003]; vector < int > nxt[_]; int col[_];

bool color(int x , int c){
	col[x] = c; for(auto t : nxt[x]) if(!col[t] && !color(t , 3 - c)) return 0; else if(col[t] == col[x]) return 0;
	return 1;
}

int dst[_]; struct edge{int s , t , w;};
int work(int x){
	memset(dst , -0x3f , sizeof(dst)); dst[x] = 0; vector < edge > pot;
	for(int i = 1 ; i <= M ; ++i)
		if(tp[i]){pot.push_back((edge){s[i] , t[i] , 1}); pot.push_back((edge){t[i] , s[i] , -1});}
		else{pot.push_back((edge){s[i] , t[i] , -1}); pot.push_back((edge){t[i] , s[i] , -1});}
	bool trs = 1; for(int i = 1 ; trs && i <= N + 1 ; ++i){trs = 0; for(auto t : pot){if(dst[t.s] + t.w > dst[t.t]){trs = 1; dst[t.t] = dst[t.s] + t.w;}}}
	if(trs){puts("NO"); exit(0);}
	int mn = 1e9; for(int i = 1 ; i <= N ; ++i) mn = min(mn , dst[i]);
	return -mn;
}

int main(){
	cin >> N >> M; for(int i = 1 ; i <= M ; ++i){cin >> s[i] >> t[i] >> tp[i]; nxt[s[i]].push_back(t[i]); nxt[t[i]].push_back(s[i]);}
	if(!color(1 , 1)){puts("NO"); return 0;}
	int ans = 0 , pos = 1;
	for(int i = 1 ; i <= N ; ++i){
		int v = work(i);
		if(ans < v){ans = v; pos = i;}
	}
	work(pos); puts("YES"); printf("%d\n" , ans); for(int i = 1 ; i <= N ; ++i) printf("%d " , dst[i] + 200000);
	return 0;
}