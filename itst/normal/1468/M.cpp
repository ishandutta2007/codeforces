#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

#define ull unsigned long long
struct BS{
	ull val[100000 / 64 + 1]; ull& operator [](int x){return val[x];}
	BS(){memset(val , 0 , sizeof(val));}
	void set(int x){val[x >> 6] |= 1ull << (x & 63);}
	void reset(int x){val[x >> 6] &= ~(1ull << (x & 63));}
	bool qry(int x){return val[x >> 6] >> (x & 63) & 1;}
	void reset(){memset(val , 0 , sizeof(val));}
	friend int merge(BS &p , BS q){
		for(int i = 0 ; i < 100000/64+1 ; ++i)
			if(p[i] & q[i]) return i * 64 + __builtin_ctzll(p[i] & q[i]); else p[i] |= q[i];
		return -1;
	}
};
map < int , int > id; int N , T;
vector < pair < int , int > > nxt[100003];
vector < int > lft[100003] , pt[100003];

int main(){
	vector < pair < BS , int > > pot;
	for(T = read() ; T ; --T){
		N = read(); id.clear(); int cid = 0; pot.clear(); map < int , int > cnt;
		for(int i = 1 ; i <= N ; ++i){pt[i].clear(); int C = read(); for(int j = 1 ; j <= C ; ++j){int x = read(); pt[i].push_back(x); ++cnt[x];}}
		for(auto t : cnt) if(t.second >= 2) id[t.first] = ++cid;
		for(int i = 1 ; i <= N ; ++i){
			vector < int > tmp; for(auto t : pt[i]) if(id.find(t) != id.end()) tmp.push_back(id[t]);
			pt[i] = tmp; sort(pt[i].begin() , pt[i].end()); int C = tmp.size();
			if(C <= sqrt(1e5)) for(int p = 0 ; p < C ; ++p) for(int q = p + 1 ; q < C ; ++q) nxt[pt[i][p]].push_back(make_pair(pt[i][q] , i));
			else{BS tmp; for(auto x : pt[i]){lft[x].push_back(pot.size()); tmp.set(x);} pot.push_back(make_pair(tmp , i));}
		}

		int px = 0 , py = 0;
		for(int i = 1 ; !px && i <= cid ; ++i){
			static int dir[100003]; BS tmp;
			for(auto r : nxt[i]){if(dir[r.first]){px = dir[r.first]; py = r.second;} tmp.set(r.first); dir[r.first] = r.second;}
			for(int p = 0 ; !px && p < lft[i].size() ; ++p){
				int r = merge(tmp , pot[lft[i][p]].first); if(r == -1){tmp.reset(i); continue;}
				if(dir[r]){px = dir[r]; py = pot[lft[i][p]].second;}
				else{for(int j = 0 ; j < p ; ++j) if(pot[lft[i][j]].first.qry(r)){px = pot[lft[i][j]].second; py = pot[lft[i][p]].second; break;}}
			}
			for(auto r : nxt[i]) dir[r.first] = 0;
		}
		if(!px) puts("-1"); else printf("%d %d\n" , px , py);
		for(int i = 1 ; i <= cid ; ++i){nxt[i].clear(); lft[i].clear();}
	}
	return 0;
}