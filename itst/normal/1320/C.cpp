#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<cmath>
#include<iomanip>
using namespace std;

int read(){
	int a = 0; char c = getchar(); bool f = 0; while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return f ? -a : a;
}

#define PII pair < int , int >
int N , M , P; vector < PII > wep; map < int , int > arm;
struct mons{int x , y , v;}; vector < mons > mon;

#define mid ((l + r) >> 1)
#define lch (x << 1)
#define rch (x << 1 | 1)
const int _ = 4e6 + 15;
int mrk[_] , mx[_];
void mark(int x , int v){mrk[x] += v; mx[x] += v;}
void down(int x){if(mrk[x]){mark(lch , mrk[x]); mark(rch , mrk[x]); mrk[x] = 0;}}

void init(int x , int l , int r){
	if(l == r) mx[x] = arm.find(l) == arm.end() ? -2e9 : -arm[l];
	else{init(lch , l , mid); init(rch , mid + 1 , r); mx[x] = max(mx[lch] , mx[rch]);}
}

void modify(int x , int l , int r , int L , int R , int v){
	if(l >= L && r <= R) return mark(x , v);
	down(x); if(mid >= L) modify(lch , l , mid , L , R , v);
	if(mid < R) modify(rch , mid + 1 , r , L , R , v);
	mx[x] = max(mx[lch] , mx[rch]);
}

int main(){
	N = read(); M = read(); P = read();
	for(int i = 1 ; i <= N ; ++i){int x = read() , c = read(); wep.push_back(make_pair(x , c));}
	for(int i = 1 ; i <= M ; ++i){int x = read() , c = read(); arm.find(x) == arm.end() ? arm[x] = c : arm[x] = min(arm[x] , c);}
	for(int i = 1 ; i <= P ; ++i){int x = read() , y = read() , c = read(); mon.push_back((mons){x , y ,c});}
	sort(wep.begin() , wep.end()); sort(mon.begin() , mon.end() , [&](mons p , mons q){return p.x < q.x;});
	int pos = 0 , ans = -2e9; init(1 , 1 , 1e6 + 1);
	for(auto t : wep){
		while(pos < mon.size() && mon[pos].x < t.first){
			modify(1 , 1 , 1e6 + 1 , mon[pos].y + 1 , 1e6 + 1 , mon[pos].v); ++pos;
		}
		ans = max(ans , mx[1] - t.second);
	}
	cout << ans;
	return 0;
}