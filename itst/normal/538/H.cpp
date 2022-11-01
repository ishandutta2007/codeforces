#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

const int _ = 1e5 + 7 , __ = _ * 40;
#define mid ((l + r) >> 1)
int ch[__][2] , mrk[__] , cnt; pair < int , int > mx[__];
void mark(int x , int v){mrk[x] += v; mx[x].first += v;}
void modify(int &x , int l , int r , int L , int R , int val){
	if(!x){x = ++cnt; mx[x].second = l;}
	if(l >= L && r <= R) return mark(x , val);
	if(mid >= L) modify(ch[x][0] , l , mid , L , R , val);
	if(mid < R) modify(ch[x][1] , mid + 1 , r , L , R , val);
	mx[x] = max(mx[ch[x][0]] , mx[ch[x][1]]); mx[x].first += mrk[x];
}

pair < int , int > qry(int x , int l , int r , int L , int R){
	if(l >= L && r <= R) return make_pair(mx[x].first , mx[x].second == 0 ? l : mx[x].second);
	pair < int , int > mx(0 , 0); if(mid >= L) mx = qry(ch[x][0] , l , mid , L , R);
	if(mid < R) mx = max(mx , qry(ch[x][1] , mid + 1 , r , L , R));
	return make_pair(mx.first + mrk[x] , mx.second);
}

int t , T , N , M , col[_] , l[_] , r[_]; vector < int > nxt[_];
void dfs(int x , int c , vector < int > &L , vector < int > &R){
	col[x] = c; (!c ? L : R).push_back(x);
	for(auto t : nxt[x])
		if(col[t] == c){puts("IMPOSSIBLE"); exit(0);}
		else if(col[t] == -1) dfs(t , c ^ 1 , L , R);
}

struct mdy{int pos , l , r , val;}; vector < mdy > now;
void push(int p , int l , int r , int v){now.push_back((mdy){p , l , r , v});}

int main(){
	t = read(); T = read(); N = read(); M = read(); memset(col , -1 , sizeof(col));
	for(int i = 1 ; i <= N ; ++i){l[i] = read(); r[i] = read();}
	for(int i = 1 ; i <= M ; ++i){int x = read() , y = read(); nxt[x].push_back(y); nxt[y].push_back(x);}

	int num = 0;
	for(int i = 1 ; i <= N ; ++i)
		if(col[i] == -1){
			int l1 = 0 , r1 = 1e9 , l2 = 0 , r2 = 1e9;
			vector < int > L , R; dfs(i , 0 , L , R); ++num;
			for(auto t : L){l1 = max(l1 , l[t]); r1 = min(r1 , r[t]);}
			for(auto t : R){l2 = max(l2 , l[t]); r2 = min(r2 , r[t]);}
			if(l1 > l2 || l1 == l2 && r1 < r2){swap(l1 , l2); swap(r1 , r2);}
			if(l1 > r1 || l2 > r2){puts("IMPOSSIBLE"); return 0;}
			if(r2 <= r1){
				push(l1 , l2 , r2 , 1); push(l2 , l2 , r2 , -1); push(l2 , l1 , r1 , 1);
				push(r2 + 1 , l1 , r1 , -1); push(r2 + 1 , l2 , r2 , 1); push(r1 + 1 , l2 , r2 , -1);
			}
			else if(l2 <= r1){
				push(l1 , l2 , r2 , 1); push(l2 , l2 , r2 , -1); push(l2 , l1 , r2 , 1);
				push(r1 + 1 , l1 , r2 , -1); push(r1 + 1 , l1 , r1 , 1); push(r2 + 1 , l1 , r1 , -1);
			}
			else{
				push(l1 , l2 , r2 , 1); push(r1 + 1 , l2 , r2 , -1);
				push(l2 , l1 , r1 , 1); push(r2 + 1 , l1 , r1 , -1);
			}
		}

	sort(now.begin() , now.end() , [&](mdy x , mdy y){return x.pos < y.pos;});
	int pos = 0 , rt = 0 , P1 = -1 , P2 = -1; now.push_back((mdy){T + 1 , 0 , 0 , 0});
	while(pos < now.size() && now[pos].pos <= T){
		int p1 = pos;
		while(now[p1].pos == now[pos].pos){modify(rt , 0 , 1e9 , now[pos].l , now[pos].r , now[pos].val); ++pos;}
		int L = max(0 , t - now[pos].pos + 1) , R = T - now[p1].pos;
		pair < int , int > mx = qry(1 , 0 , 1e9 , L , R);
		if(mx.first == num){P1 = mx.second; P2 = min(now[pos].pos - 1 , T - P1); break;}
	}

	if(P1 == -1) puts("IMPOSSIBLE");
	else{
		puts("POSSIBLE"); printf("%d %d\n" , P1 , P2);
		memset(col , -1 , sizeof(col));
		for(int i = 1 ; i <= N ; ++i)
			if(col[i] == -1){
				int l1 = 0 , r1 = 1e9 , l2 = 0 , r2 = 1e9; vector < int > L , R; dfs(i , 0 , L , R);
				for(auto t : L){l1 = max(l1 , l[t]); r1 = min(r1 , r[t]);}
				for(auto t : R){l2 = max(l2 , l[t]); r2 = min(r2 , r[t]);}
				if(!(l1 <= P1 && r1 >= P1 && l2 <= P2 && r2 >= P2)){
					for(auto t : L) col[t] ^= 1;
					for(auto t : R) col[t] ^= 1;
				}
			}
		for(int i = 1 ; i <= N ; ++i) putchar(col[i] + '1');
	}
	return 0;
}