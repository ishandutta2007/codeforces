#include<bits/stdc++.h>
//this code is written by Itst
using namespace std;

namespace flow{
	const int _ = 1e5 + 3 , __ = 1e6 + 3;
	struct Edge{
		int end , upEd , f;
	}Ed[__];
	int head[_] , cur[_] , flo[_] , S , T , cntEd = 1;
	
	void addEd(int a , int b , int c){
		Ed[++cntEd] = (Edge){b , head[a] , c};
		head[a] = cntEd;
	}
	
	void addE(int a , int b , int c){addEd(a , b , c); addEd(b , a , 0);}

	queue < int > q;
	bool bfs(){
		memset(flo , 0 , sizeof(int) * (T + 1));
		flo[S] = 1;
		while(!q.empty()) q.pop();
		q.push(S);
		while(!q.empty()){
			int t = q.front(); q.pop();
			for(int i = head[t] ; i ; i = Ed[i].upEd)
				if(!flo[Ed[i].end] && Ed[i].f){
					flo[Ed[i].end] = flo[t] + 1;
					if(Ed[i].end == T){
						memcpy(cur , head , sizeof(int) * (T + 1));
						return 1;
					}
					q.push(Ed[i].end);
				}
		}
		return 0;
	}

	int dfs(int x , int minN){
		if(x == T) return minN;
		int sum = 0;
		for(int &i = cur[x] ; i ; i = Ed[i].upEd)
			if(flo[Ed[i].end] == flo[x] + 1 && Ed[i].f){
				int t = dfs(Ed[i].end , min(minN - sum , Ed[i].f));
				sum += t; Ed[i].f -= t; Ed[i ^ 1].f += t;
				if(sum == minN) break;
			}
		return sum;
	}

	int Dinic(int s , int t){
		S = s; T = t;
		int sum = 0;
		while(bfs()) sum += dfs(S , 1e9);
		return sum;
	}
}

#define PII pair < int , int >
int N , M , arr[203] , cnt[203];
vector < PII > zyz[203];

void divide(int id){
	int x = arr[id]; cnt[id] = cnt[id - 1];
	for(int i = 2 ; i * i <= x ; ++i)
		if(x % i == 0){
			++cnt[id]; int num = 0;
			while(x % i == 0){
				x /= i; ++num;
			}
			zyz[id].push_back(PII(i , num));
		}
	if(x - 1){
		++cnt[id];
		zyz[id].push_back(PII(x , 1));
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
#endif
	cin >> N >> M;
	for(int i = 1 ; i <= N ; ++i){
		cin >> arr[i];
		divide(i);
	}
	for(int i = 1 ; i <= N ; ++i)
		for(int j = 0 ; j < zyz[i].size() ; ++j)
			if(i & 1)
				flow::addE(0 , cnt[i - 1] + j + 1 , zyz[i][j].second);
			else
				flow::addE(cnt[i - 1] + j + 1 , cnt[N] + 1 , zyz[i][j].second);
	for(int i = 1 ; i <= M ; ++i){
		int a , b; cin >> a >> b;
		if(b & 1) swap(a , b);
		for(int j = 0 ; j < zyz[a].size() ; ++j)
			for(int k = 0 ; k < zyz[b].size() ; ++k)
				if(zyz[a][j].first == zyz[b][k].first)
					flow::addE(cnt[a - 1] + j + 1 , cnt[b - 1] + k + 1 , 1e9);
	}
	cout << flow::Dinic(0 , cnt[N] + 1);
	return 0;
}