#include<bits/stdc++.h>
using namespace std;

const int _ = 1e5 + 7 , __ = 4e5 + 7;
int N , cnt; struct line{int x , y , id;}now[4403];

namespace flow{
	struct Edge{int end , upEd , f , c;}Ed[__];
	int head[_] , dis[_] , cntEd , S , T;
	void addEd(int a , int b , int c , int d){Ed[++cntEd] = (Edge){b , head[a] , c , d}; head[a] = cntEd;}
	void addE(int a , int b , int c , int d = 0){addEd(a , b , c , d); addEd(b , a , 0 , -d);}
	
	bool vis[_]; queue < int > q;
	bool SPFA(){
		memset(dis , 0x3f , sizeof(int) * (T + 2)); dis[S] = 0; q.push(S);
		while(!q.empty()){
			int t = q.front(); q.pop(); vis[t] = 0;
			for(int i = head[t] ; i ; i = Ed[i].upEd)
				if(Ed[i].f && dis[Ed[i].end] > dis[t] + Ed[i].c){
					dis[Ed[i].end] = dis[t] + Ed[i].c;
					if(!vis[Ed[i].end]){vis[Ed[i].end] = 1; q.push(Ed[i].end);}
				}
		}
		return dis[T] != dis[T + 1];
	}

	int cur[_];
	int dfs(int x , int mn){
		if(x == T) return mn;
		vis[x] = 1; int sum = 0;
		for(int &i = cur[x] ; i ; i = Ed[i].upEd)
			if(Ed[i].f && dis[Ed[i].end] == dis[x] + Ed[i].c && !vis[Ed[i].end]){
				int t = dfs(Ed[i].end , min(mn , Ed[i].f));
				Ed[i].f -= t; Ed[i ^ 1].f += t; sum += t;
				if(sum == mn) break;
			}
		vis[x] = 0; return sum;
	}

	pair < int , int > dinic(){
		int sum1 = 0 , sum2 = 0;
		while(SPFA()){
			memcpy(cur , head , sizeof(int) * (T + 1));
			int t = dfs(S , 1e9); sum1 += t; sum2 += dis[T] * t;
		}
		return make_pair(sum1 , sum2);
	}
}using flow::addE;

line tmp[2203];

void link(long long mid , bool flg){
	cnt = 2 * N; memset(flow::head , 0 , sizeof(int) * (flow::T + 1)); flow::cntEd = 1;
	for(int i = 1 ; i <= N ; ++i) addE(0 , i , 1);
	sort(tmp + 1 , tmp + N + 1 , [&](line p , line q){return p.x * mid + p.y < q.x * mid + q.y;});
	sort(now + 1 , now + 2 * N + 1 , [&](line p , line q){return p.y < q.y || p.y == q.y && p.id > q.id;});
	int pre = 0 , pos = 1;
	for(int i = 1 ; i <= 2 * N ; ++i){
		long long val = now[i].x * mid + now[i].y;
		while(pos <= N && tmp[pos].x * mid + tmp[pos].y <= val){
			++cnt; if(pre) addE(cnt , pre , 1e9);
			addE(cnt , tmp[pos].id , 1); pre = cnt; ++pos;
		}
		if(now[i].id <= N) addE(now[i].id , pre , 1 , flg);
	}
}

bool check(long long mid){
	link(mid , 0); flow::T = ++cnt; for(int i = 1 ; i <= N ; ++i) addE(i + N , cnt , 1);
	return flow::dinic().first == N;
}

void calc(long long ans){
	link(ans , 1); int pre = 0;
	for(int i = 1 ; i <= 2 * N ; ++i)
		if(now[i].id > N){
			++cnt; if(pre) addE(cnt , pre , 1e9);
			addE(cnt , now[i].id , 1); pre = cnt;
		}else addE(now[i].id , pre , 1);
	sort(now + 1 , now + 2 * N + 1 , [&](line p , line q){
			return p.x * ans + p.y < q.x * ans + q.y || p.x * ans + p.y == q.x * ans + q.y && p.id > q.id;
		}); pre = 0;
	for(int i = 1 ; i <= 2 * N ; ++i)
		if(now[i].id > N){
			++cnt; if(pre) addE(cnt , pre , 1e9);
			addE(cnt , now[i].id , 1); pre = cnt;
		}else addE(now[i].id , pre , 1);
	flow::T = ++cnt; for(int i = 1 ; i <= N ; ++i) addE(i + N , cnt , 1);
	cout << ans << ' ' << flow::dinic().second + N << endl;
}

int main(){
	cin >> N; for(int i = 1 ; i <= 2 * N ; ++i){cin >> now[i].x >> now[i].y; now[i].id = i;}
	for(int i = N + 1 ; i <= 2 * N ; ++i) tmp[i - N] = now[i];
	if(!check(1e9 + 1)) puts("-1");
	else{int L = 0 , R = 1e9; while(L < R){int mid = (L + R) >> 1; check(mid) ? R = mid : L = mid + 1;} calc(L);}
	return 0;
}