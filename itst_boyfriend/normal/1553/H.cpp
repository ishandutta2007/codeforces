#include<bits/stdc++.h>
using namespace std;

const int _ = 1 << 19 , __ = _ * 2 + 3; int ch[__][2] , sz[__] , N , K;
void ins(int v){int rt = 1; ++sz[1]; for(int i = K - 1 ; ~i ; --i){rt = rt << 1 | (v >> i & 1); ++sz[rt];}}

struct dat{
	vector < int > mn , mx , ans;
	void ext(bool flg){
		int sz = mn.size();
		for(int i = 0 ; i < sz ; ++i){mn.push_back(mn[i] + sz); mx.push_back(mx[i] + sz); ans.push_back(ans[i]);}
		if(flg){for(auto &t : mn){t ^= sz;} for(auto &t : mx){t ^= sz;}}
	}
};
dat merge(dat p , dat q){
	p.ext(0); q.ext(1); int sz = p.mn.size();
	for(int i = 0 ; i < sz ; ++i){
		p.ans[i] = min(min(p.ans[i] , q.ans[i]) , min(abs(q.mn[i] - p.mx[i]) , abs(q.mx[i] - p.mn[i])));
		p.mn[i] = min(p.mn[i] , q.mn[i]); p.mx[i] = max(p.mx[i] , q.mx[i]);
	}
	return p;
}
dat emptydat(int sz){
	dat temp; temp.mn.resize(sz , 1000000000); temp.mx.resize(sz , -1000000000);
	temp.ans.resize(sz , 1000000000); return temp;
}

dat solve(int floor , int x){
	if(!sz[x]) return emptydat(1 << floor);
	if(!floor){dat temp; temp.mn.push_back(0); temp.mx.push_back(0); temp.ans.push_back(1e9); return temp;}
	return merge(solve(floor - 1 , x << 1) , solve(floor - 1 , x << 1 | 1));
}

int main(){
	ios::sync_with_stdio(0); cin >> N >> K;
	for(int i = 1 ; i <= N ; ++i){int v; cin >> v; ins(v);}
	vector < int > ans = solve(K , 1).ans; for(auto t : ans) cout << t << ' ';
	return 0;
}