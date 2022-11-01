#include<bits/stdc++.h>
//This code is written by Itst
#define lch (x << 1)
#define rch (x << 1 | 1)
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

const int MAXN = 2e5 + 10;
struct Edge{
	int end , upEd;
}Ed[MAXN << 1];
deque < int > zys[MAXN];
int prime[MAXN] , head[MAXN] , cnt , cnt1 , N , cntEd , ans , mDis , mInd;
bool vis[MAXN] , nonp[MAXN];
map < int , int > lsh;
queue < int > q;

inline void addEd(int a , int b){
	Ed[++cntEd].end = b;
	Ed[cntEd].upEd = head[a];
	head[a] = cntEd;
}

void init(){
	for(int i = 2 ; i <= 1000 ; ++i){
		if(!nonp[i])
			prime[++cnt] = i;
		for(int j = 1 ; prime[j] * i <= 1000 ; ++j){
			nonp[prime[j] * i] = 1;
			if(i % prime[j] == 0)
				break;
		}
	}
	cnt1 = cnt;
}

void bfs(int x , int t){
	q.push(x);
	vis[x] = 1;
	while(!q.empty()){
		x = q.front();
		q.pop();
		for(int i = head[x] ; i ; i = Ed[i].upEd)
			if(!vis[Ed[i].end]){
				deque < int > :: iterator it = lower_bound(zys[Ed[i].end].begin() , zys[Ed[i].end].end() , t);
				if(it != zys[Ed[i].end].end() && *it == t){
					vis[Ed[i].end] = 1;
					zys[Ed[i].end].erase(it);
					q.push(Ed[i].end); 
				}
			}
	}
}

void dfs(int x , int p , int l , bool f = 0){
	if(mDis < l){
		mDis = l;
		mInd = x;
	}
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(vis[Ed[i].end] && Ed[i].end != p)
			dfs(Ed[i].end , x , l + 1 , f);
	if(f)
		vis[x] = 0;
}

void calc(int x){
	int t = zys[x][0];
	zys[x].pop_front();
	bfs(x , t);
	mDis = -1;
	dfs(x , 0 , 0);
	mDis = -1;
	dfs(mInd , 0 , 0 , 1);
	ans = max(ans , mDis);
}

int main(){
	init();
	N = read();
	bool f = 1;
	for(int i = 1 ; i <= N ; ++i){
		int a = read();
		for(int j = 1 ; j <= cnt && prime[j] * prime[j] <= a ; ++j)
			if(a % prime[j] == 0){
				zys[i].push_back(j);
				while(a % prime[j] == 0)
					a /= prime[j];
			}
		if(a != 1)
			if(prime[cnt] >= a)
				zys[i].push_back(lower_bound(prime + 1 , prime + cnt + 1 , a) - prime);
			else
				if(lsh.count(a))
					zys[i].push_back(lsh[a]);
				else
					zys[i].push_back(lsh[a] = ++cnt1);
		if(zys[i].size())
			f = 0;
	}
	for(int i = 1 ; i < N ; ++i){
		int a = read() , b = read();
		addEd(a , b);
		addEd(b , a);
	}
	for(int i = 1 ; i <= N ; ++i)
		sort(zys[i].begin() , zys[i].end());
	for(int i = 1 ; i <= N ; ++i)
		while(zys[i].size())
			calc(i);
	if(!f)
		cout << ans + 1;
	else
		puts("0");
	return 0;
}