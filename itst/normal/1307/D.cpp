#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

const int _ = 2e5 + 7;
struct Edge{int end , upEd;}Ed[_ << 1];
int dist[2][_] , N , M , K , P[_] , head[_] , cntEd;
void addEd(int a , int b){Ed[++cntEd] = (Edge){b , head[a]}; head[a] = cntEd;}

void bfs(int* dis , int st){
	memset(dis , 0x3f , sizeof(int) * (N + 1));
	dis[st] = 0; queue < int > q; q.push(st);
	while(!q.empty()){
		int t = q.front(); q.pop();
		for(int i = head[t] ; i ; i = Ed[i].upEd)
			if(dis[Ed[i].end] == dis[0]){
				q.push(Ed[i].end); dis[Ed[i].end] = dis[t] + 1;
			}
	}
}

struct query{int l1 , l2 , id;}now[_] , thn[_];
bool check(int mid){
	int cnt = 0;
	for(int i = 1 ; i <= K ; ++i)
		if(dist[0][P[i]] >= mid && dist[1][P[i]] >= mid) return 1;
		else{
			now[++cnt] = (query){mid - dist[1][P[i]] - 1 , mid - dist[0][P[i]] - 1 , P[i]};
			thn[cnt] = (query){dist[0][P[i]] , dist[1][P[i]] , P[i]};
		}
	sort(now + 1 , now + cnt + 1 , [&](query p , query q){return p.l1 > q.l1;});
	sort(thn + 1 , thn + cnt + 1 , [&](query p , query q){return p.l1 > q.l1;});
	query mx1 = (query){0 , -1000000000 , 0} , mx2 = (query){0 , -1000000000 , 0}; int pos = 1;
	for(int i = 1 ; i <= cnt ; ++i){
		while(pos <= cnt && thn[pos].l1 >= now[i].l1){
			if(thn[pos].l2 > mx1.l2){mx2 = mx1; mx1 = thn[pos];}
			else if(thn[pos].l2 > mx2.l2) mx2 = thn[pos];
			++pos;
		}
		if(mx2.l2 >= now[i].l2 || (mx1.l2 >= now[i].l2 && mx1.id != now[i].id)) return 1;
	}
	return 0;
}

int main(){
	scanf("%d %d %d" , &N , &M , &K);
	for(int i = 1 ; i <= K ; ++i) scanf("%d" , &P[i]);
	for(int i = 1 ; i <= M ; ++i){int x , y; scanf("%d %d" , &x , &y); addEd(x , y); addEd(y , x);}
	bfs(dist[0] , 1); bfs(dist[1] , N);
	int L = 1 , R = dist[0][N];
	while(L < R){int mid = (L + R + 1) >> 1; check(mid) ? L = mid : R = mid - 1;}
	printf("%d\n" , L); return 0;
}