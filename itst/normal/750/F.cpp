#include<bits/stdc++.h>
//this code is written by Itst
using namespace std;

inline int read(){
	int a = 0;
	char c = getchar();
	bool f = 0;
	while(!isdigit(c)){
		if(c == '-')
			f = 1;
		c = getchar();
	}
	while(isdigit(c)){
		a = (a << 3) + (a << 1) + (c ^ '0');
		c = getchar();
	}
	return f ? -a : a;
}

int h , K;
vector < int > nei[200] , v1 , v2;
int dep[200] , cnt;
bool vis[200];

inline void answer(int x){
	cout << "! " << x << endl;
	fflush(stdout);
}

inline bool ask(int x){
	if(++cnt == 17){
		answer(x);
		return 1;
	}
	vis[x] = 1;
	cout << "? " << x << endl;
	fflush(stdout);
	K = read();
	if(!K)
		exit(0);
	for(int i = 1 ; i <= K ; ++i)
		nei[x].push_back(read());
	if(K == 2){
		answer(x);
		return 1;
	}
	return 0;
}

bool get(int st , vector < int > &v){
	do{
		if(ask(st))
			return 1;
		v.push_back(st);
		if(K == 3)
			for(int i = 0 ; i < 3 ; ++i)
				if(!vis[nei[st][i]]){
					st = nei[st][i];
					break;
				}
	}while(K != 1);
	return 0;
}

inline void up(int& now){
	int k = dep[now];
	for(int i = 0 ; (i << 1) + h - k < v1.size() ; ++i){
		dep[v1[i]] = dep[now] - 1;
		now = v1[i];
	}
	for(int i = 0 ; i < 3 ; ++i)
		if(!vis[nei[now][i]]){
			dep[nei[now][i]] = dep[now] - 1;
			now = nei[now][i];
			break;
		}
}

void solve(){
	if(ask(1))
		return;
	int now = 1;
	if(K == 1){
		dep[now] = h;
		dep[nei[now][0]] = h - 1;
		now = nei[now][0];
	}
	else{
		if(get(nei[now][0] , v1) || get(nei[now][1] , v2))
			return;
		if(v1.size() < v2.size())
			swap(v1 , v2);
		dep[now] = h - v2.size();
		up(now);
	}
	while(dep[now] > 3){
		if(ask(now))
			return;
		if(vis[nei[now][0]])
			swap(nei[now][0] , nei[now][2]);
		if(vis[nei[now][1]])
			swap(nei[now][1] , nei[now][2]);
		v1.clear();
		if(get(nei[now][0] , v1))
			return;
		up(now);
	}
	if(dep[now] == 1){
		answer(now);
		return;
	}
	ask(now);
	for(int i = 0 ; i < nei[now].size() ; ++i)
		if(!vis[nei[now][i]])
			if(ask(nei[now][i]))
				return;
			else
				if(dep[now] == 3)
					for(int j = 0 ; j < nei[nei[now][i]].size() ; ++j)
						if(!vis[nei[nei[now][i]][j]] && ask(nei[nei[now][i]][j]))
							return;
}

int main(){
	for(int T = read() ; T ; --T){
		cnt = 0;
		v1.clear();
		v2.clear();
		memset(vis , 0 , sizeof(vis));
		memset(dep , 0 , sizeof(dep));
		for(int i = 1 ; i <= 128 ; ++i)
			nei[i].clear();
		h = read();
		if(!h)
			return 0;
		solve();
	}
	return 0;
}