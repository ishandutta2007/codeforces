#include<bits/stdc++.h>
using namespace std;

const int _ = 2e5 + 7; vector < int > nxt[_]; int N , M , fa[_] , dep[_]; bool vis[_];
pair < int , int > mrk[_];

vector < int > qroute(int x , int p1 , int p2 , int y){
	vector < int > tmp; tmp.push_back(x);
	for(int i = x ; i != p1 ; i = fa[i]) tmp.push_back(fa[i]);
	for(int i = p2 ; i != y ; i = fa[i]) tmp.push_back(i);
	tmp.push_back(y); return tmp;
}

void getanswer(pair < int , int > p , pair < int , int > q , int y){
	int x = dep[p.second] > dep[q.second] ? p.second : q.second; cout << "YES" << endl;
	vector < int > pot[3]; pot[0].push_back(y); for(int i = y ; i != x ; i = fa[i]) pot[0].push_back(fa[i]);
	reverse(pot[0].begin() , pot[0].end()); pot[1] = qroute(x , p.second , p.first , y); pot[2] = qroute(x , q.second , q.first , y);
	for(int i = 0 ; i < 3 ; ++i , cout << endl){cout << pot[i].size() << ' '; for(auto t : pot[i]) cout << t << ' ';}
	exit(0);
}

void dfs(int x , int p){
	dep[x] = dep[p] + 1; fa[x] = p;
	for(auto t : nxt[x])
		if(t != p)
			if(!dep[t]) dfs(t , x);
			else if(dep[t] < dep[x])
				for(int p = x ; p != t ; p = fa[p])
					if(mrk[p] != mrk[0]) getanswer(make_pair(x , t) , mrk[p] , p);
					else mrk[p] = make_pair(x , t);
}

int main(){
	ios::sync_with_stdio(0); cin >> N >> M;
	for(int i = 1 ; i <= M ; ++i){int p , q; cin >> p >> q; nxt[p].push_back(q); nxt[q].push_back(p);}
	for(int i = 1 ; i <= N ; ++i) if(!dep[i]) dfs(i , 0);
	cout << "NO"; return 0;
}