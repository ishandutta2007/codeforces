#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

#define PII pair < int , int >
#define VII vector < PII >
int lim , N , Q;

const int _ = 1.5e5 + 7;
int val[_]; VII pot;
VII operator +(VII &p , const VII q){
	pot.clear();
	for(auto t : p) val[t.second] += t.first;
	for(auto t : q) val[t.second] += t.first;
	for(auto t : p){pot.push_back(PII(val[t.second] , t.second)); val[t.second] = 0;}
	for(auto t : q) if(val[t.second]){pot.push_back(PII(val[t.second] , t.second)); val[t.second] = 0;}
	sort(pot.begin() , pot.end()); reverse(pot.begin() , pot.end());
	while(pot.size() > lim){
		for(int i = pot.size() - lim ; i < pot.size() ; ++i) pot[i].first -= pot.back().first;
		while(!pot.back().first) pot.pop_back();
	}
	return pot;
}

#define mid ((l + r) >> 1)
#define lch (x << 1)
#define rch (x << 1 | 1)
VII tr[_ << 2]; int mrk[_ << 2] , len[_ << 2];

void init(int x , int l , int r){
	mrk[x] = -1; len[x] = r - l + 1;
	if(l == r) tr[x].push_back(make_pair(1 , read()));
	else{init(lch , l , mid); init(rch , mid + 1 , r); tr[x] = tr[lch] + tr[rch];}
}

void mark(int x , int v){tr[x] = {PII(len[x] , v)}; mrk[x] = v;}
void down(int x){if(~mrk[x]){mark(lch , mrk[x]); mark(rch , mrk[x]); mrk[x] = -1;}}

void modify(int x , int l , int r , int L , int R , int v){
	if(l >= L && r <= R) return mark(x , v);
	down(x); if(mid >= L) modify(lch , l , mid , L , R , v);
	if(mid < R) modify(rch , mid + 1 , r , L , R , v);
	tr[x] = tr[lch] + tr[rch];
}

VII qry(int x , int l , int r , int L , int R){
	if(l >= L && r <= R) return tr[x];
	if(~mrk[x]) return (VII){PII(min(R , r) - max(L , l) + 1 , mrk[x])};
	VII pot; if(mid >= L) pot = qry(lch , l , mid , L , R);
	if(mid < R) pot = pot + qry(rch , mid + 1 , r , L , R);
	return pot;
}

int main(){
	N = read(); Q = read(); lim = 100 / read(); init(1 , 1 , N);
	while(Q--)
		if(read() == 1){int l = read() , r = read() , id = read(); modify(1 , 1 , N , l , r , id);}
		else{
			int l = read() , r = read(); VII pot = qry(1 , 1 , N , l , r);
			printf("%d " , pot.size()); for(auto t : pot) printf("%d " , t.second); putchar('\n');
		}
	return 0;
}