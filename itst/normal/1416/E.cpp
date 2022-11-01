#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

#define int long long
#define pii pair < int , int >
#define st first
#define nd second
struct Set{
	map < int , int > id;
	bool qry(int x){auto p = id.upper_bound(x); return p != id.begin() && (--p)->nd >= x;}
	void ins(int x){auto p = id.upper_bound(x); if(p == id.begin() || (--p)->nd < x) id[x] = x;}
};

struct dat{
	Set p; int lim , ans , tms , add;
	int val(int p){return p * tms + add;} int rval(int p){return tms * (p - add);}
	void reset(){p.id = {{min(rval(1) , rval(lim - 1)) , max(rval(1) , rval(lim - 1))}};}
	bool shift(int x){
		while(p.id.size()){
			auto t = tms == 1 ? --p.id.end() : p.id.begin();
			if(min(val(t->st) , val(t->nd)) >= x) p.id.erase(t);
			else if(max(val(t->st) , val(t->nd)) < x) break;
			else{pii tmp = *t; p.id.erase(t); (tms == 1 ? tmp.nd : tmp.st) = rval(x - 1); p.id.insert(tmp); break;}
		}
		lim = x; tms *= -1; add = x - add; if(p.id.empty()){reset(); return 0;} ++ans; return 1;
	}
	int qry(int x){int t = rval(x); return x < lim && p.qry(t);} void ins(int x){p.ins(rval(x));}
};

signed main(){
	for(int T = read() ; T ; --T){
		int N = read(); dat tmp; tmp.ans = 0; tmp.tms = 1; tmp.add = 0; tmp.lim = 1e9; tmp.reset();
		for(int i = 1 ; i <= N ; ++i){
			int A = read() , v = tmp.qry(A / 2); bool f = tmp.shift(A);
			if(!(A % 2)){if(v || !f){tmp.p.id.clear(); ++tmp.ans;} tmp.ins(A / 2);}
		}
		printf("%lld\n" , 2 * N - tmp.ans + 1);
	}
	return 0;
}