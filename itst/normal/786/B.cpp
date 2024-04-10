#include<bits/stdc++.h>
//this code is written by Itst
using namespace std;

int read(){
	int a = 0; char c = getchar();
	while(!isdigit(c)) c = getchar();
	while(isdigit(c)){
		a = a * 10 + c - 48;
		c = getchar();
	}
	return a;
}

const int _ = 1e5 + 7;

#define ll long long
struct Edge{
	int end , upEd , w;
}Ed[_ << 5];
int N , Q , S , cnt , cntEd;
int head[_ << 3];
ll dis[_ << 3];

void addEd(int a , int b , int c){
	Ed[++cntEd] = (Edge){b , head[a] , c};
	head[a] = cntEd;
}

struct segTree{
	int ind[_ << 2] , pos[_];

#define lch (x << 1)
#define rch (x << 1 | 1)
#define mid ((l + r) >> 1)
	
	void init(int x , int l , int r , bool f){
		ind[x] = ++cnt;
		if(l != r){
			init(lch , l , mid , f); init(rch , mid + 1 , r , f);
			if(!f)
				addEd(ind[x] , ind[lch] , 0) , addEd(ind[x] , ind[rch] , 0);
			else
				addEd(ind[lch] , ind[x] , 0) , addEd(ind[rch] , ind[x] , 0);
		}
		else
			pos[l] = cnt;
	}
	
	void add(int x , int l , int r , int L , int R , int to , int w , bool f){
		if(l >= L && r <= R){
			f ? addEd(ind[x] , to , w) : addEd(to , ind[x] , w);
			return;
		}
		if(mid >= L) add(lch , l , mid , L , R , to , w , f);
		if(mid < R) add(rch , mid + 1 , r , L , R , to , w , f);
	}
}from , to;

#define PLI pair < ll , int >
#define st first
#define nd second
void Dijk(){
	priority_queue < PLI > q;
	memset(dis , 0x7f , sizeof(dis));
	dis[from.pos[S]] = 0;
	q.push(PLI(0 , from.pos[S]));
	while(!q.empty()){
		PLI t = q.top(); q.pop();
		if(dis[t.nd] != -t.st) continue;
		for(int i = head[t.nd] ; i ; i = Ed[i].upEd)
			if(dis[Ed[i].end] > dis[t.nd] + Ed[i].w){
				dis[Ed[i].end] = dis[t.nd] + Ed[i].w;
				q.push(PLI(-dis[Ed[i].end] , Ed[i].end));
			}
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
#endif
	N = read(); Q = read(); S = read();
	from.init(1 , 1 , N , 1); to.init(1 , 1 , N , 0);
	for(int i = 1 ; i <= N ; ++i)
		addEd(to.pos[i] , from.pos[i] , 0);
	int a , b , c , w;
	for(int i = 1 ; i <= Q ; ++i)
		switch(read()){
		case 1:
			a = read(); b = read(); w = read();
			addEd(from.pos[a] , to.pos[b] , w);
			break;
		case 2:
			a = read(); b = read(); c = read(); w = read();
			to.add(1 , 1 , N , b , c , from.pos[a] , w , 0);
			break;
		case 3:
			a = read(); b = read(); c = read(); w = read();
			from.add(1 , 1 , N , b , c , to.pos[a] , w , 1);
		}
	Dijk();
	for(int i = 1 ; i <= N ; ++i)
		if(dis[from.pos[i]] > 1e15)
			printf("-1 ");
		else printf("%lld " , dis[from.pos[i]]);
	return 0;
}