#include<bits/stdc++.h>
#define MAXN 100001
using namespace std;
struct Edge{
	int end , w , upEd;
}Ed[MAXN << 1];
int head[MAXN] , p[MAXN] , N , cnt;
long long dis[MAXN];
inline void add(int a , int b , int c){
	Ed[++cnt].end = b;	Ed[cnt].w = c;	Ed[cnt].upEd = head[a];	head[a] = cnt;
}
void output(int t){
	if(!t)	return;
	output(p[t]);
	cout << t << ' ';
}
int main(){
	int M;
	for(scanf("%d%d" , &N , &M) ; M ; M--){
		int a , b , c;
		scanf("%d%d%d" , &a , &b , &c);
		add(a , b , c);	add(b , a , c);
	}
	memset(dis , 0x3f , sizeof(dis));
	priority_queue < pair < long long , int > > q;
	dis[1] = 0;
	q.push(make_pair(0 , 1));
	while(!q.empty() && q.top().second != N){
		int k = q.top().second;
		q.pop();
		for(int i = head[k] ; i ; i = Ed[i].upEd)
			if(dis[Ed[i].end] > dis[k] + Ed[i].w){
				dis[Ed[i].end] = dis[k] + Ed[i].w;
				p[Ed[i].end] = k;
				q.push(make_pair(-dis[Ed[i].end] , Ed[i].end));
			}
	}
	if(q.empty())	cout << -1;
	else	output(N);
	return 0;
}