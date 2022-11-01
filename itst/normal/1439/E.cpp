#include<bits/stdc++.h>
using namespace std;

const int _ = 8e5 + 7;
struct point{int x , y;}; vector < point > val; int N; point imp[_][2];
bool operator <(point p , point q){
	int dltx = p.x ^ q.x , dlty = p.y ^ q.y , vp = p.x | p.y , vq = q.x | q.y;
	if(dltx == 0 && dlty == 0) return 0;
	int i = 31 - __builtin_clz(dltx | dlty);
	if((vp >> i & 1) && (vq >> i & 1)){
		bool fl = p.x >> i & 1 , fr = q.x >> i & 1;
		if(fl != fr) return fl > fr;
	}else if(vp >> i & 1) return p.x >> i & 1; else if(vq >> i & 1) return !(q.x >> i & 1);
	return 0;
}

point lca(point p , point q){
	point ans = (point){0 , 0}; int vp = p.x | p.y , vq = q.x | q.y , upp = 30 , upq = 30;
	while(~upp && !(vp >> upp & 1)) --upp;
	while(~upq && !(vq >> upq & 1)) --upq;
	while(upp != -1 && upq != -1){
		bool fl = p.x >> upp & 1 , fr = q.x >> upq & 1; if(fl != fr) break;
		int mn = min(upp , upq); (fl ? ans.x : ans.y) |= 1 << mn;
		if(mn == upp) --upp;
		if(mn == upq) --upq;
		while(~upp && !(vp >> upp & 1)) --upp;
		while(~upq && !(vq >> upq & 1)) --upq;
	}
	return ans;
}
point fa(point x){
	int p = x.x | x.y; if(!p) return x;
	for(int i = 0 ; i <= 30 ; ++i)
		if(p >> i & 1){x.x >> i & 1 ? --x.x : --x.y;return x;}
	assert(0); return x;
}
int dep(point x){return x.x | x.y;}

map < point , int > id; point tocur[_] , stk[_]; vector < int > ch[_]; int cid , mrk[_] , top;
int qid(point x){if(id.find(x) == id.end()){id[x] = ++cid; tocur[cid] = x;} return id[x];}
vector < int > sp;
void dfs(int x , int p){
	for(auto t : ch[x]){dfs(t , x); mrk[x] += mrk[t];}
	if(mrk[x])
		if(!p){sp.push_back(1); sp.push_back(2);}
		else{sp.push_back(dep(tocur[p]) + 2); sp.push_back(dep(tocur[x]) + 2);}
}

int main(){
	ios::sync_with_stdio(0); cin >> N; vector < point > pot;
	for(int i = 0 ; i < N ; ++i){
		point x , y; cin >> x.x >> x.y >> y.x >> y.y;
		pot.push_back(x); pot.push_back(y); point d = lca(x , y);
		pot.push_back(d); pot.push_back(fa(d)); imp[i][0] = x; imp[i][1] = y;
		}
	sort(pot.begin() , pot.end());
	for(auto t : pot){
		if(top){
			point r = lca(stk[top] , t); int pre = 0;
			while(top && dep(r) <= dep(stk[top])){
				if(pre) ch[qid(stk[top])].push_back(pre);
				pre = qid(stk[top--]);
			}
			if(pre && qid(r) != pre) ch[qid(r)].push_back(pre);
			stk[++top] = r;
		}
		if(!top || qid(stk[top]) != qid(t)) stk[++top] = t;
	}
	for(int i = 1 ; i < top ; ++i) ch[qid(stk[i])].push_back(qid(stk[i + 1]));
	for(int i = 0 ; i < N ; ++i){
		++mrk[qid(imp[i][0])]; ++mrk[qid(imp[i][1])];
		point d = lca(imp[i][0] , imp[i][1]); --mrk[qid(d)];
		if(d.x | d.y) --mrk[qid(fa(d))];
	}
	dfs(qid(stk[1]) , 0);
	
	set < int > lsh; bool f = 0;
	for(auto t : sp) if(lsh.find(t) == lsh.end()) lsh.insert(t); else lsh.erase(t);
	if(lsh.size() && *lsh.begin() == 1){f = 1; lsh.erase(lsh.begin());}
	cout << lsh.size() + ((lsh.size() ^ f) & 1);
	return 0;
}