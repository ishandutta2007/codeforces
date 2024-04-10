#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
//This code is written by Itst
using namespace std;

inline int read(){
	int a = 0;
	char c = getchar();
	bool f = 0;
	while(!isdigit(c) && c != EOF){
		if(c == '-')
			f = 1;
		c = getchar();
	}
	if(c == EOF)
		exit(0);
	while(isdigit(c)){
		a = (a << 3) + (a << 1) + (c ^ '0');
		c = getchar();
	}
	return f ? -a : a;
}

const int MAXN = 20010 , MAXM = 200010;
struct Edge{
    int end , upEd , f , c;
}Ed[MAXM];
int head[MAXN] , cur[MAXN] , dep[MAXN] , num[MAXN];
int N , M , G , S , T , ans , cntEd = 1;
bool vis[MAXN];
queue < int > q;

inline void addEd(int a , int b , int c , int d = 0){
    Ed[++cntEd].end = b;
    Ed[cntEd].upEd = head[a];
    Ed[cntEd].f = c;
    Ed[cntEd].c = d;
    head[a] = cntEd;
}

inline bool bfs(){
    while(!q.empty())
        q.pop();
    q.push(S);
    memset(dep , 0 , sizeof(dep));
    dep[S] = 1;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        for(int i = head[t] ; i ; i = Ed[i].upEd)
            if(Ed[i].f && !dep[Ed[i].end]){
                dep[Ed[i].end] = dep[t] + 1;
                if(Ed[i].end == T){
                    memcpy(cur , head , sizeof(head));
                    return 1;
                }
                q.push(Ed[i].end);
            }
    }
    return 0;
}

inline int dfs(int x , int mF){
    if(x == T)
        return mF;
    int sum = 0;
    for(int &i = cur[x] ; i ; i = Ed[i].upEd)
        if(Ed[i].f && dep[Ed[i].end] == dep[x] + 1){
            int t = dfs(Ed[i].end , min(mF - sum , Ed[i].f));
            if(t){
                Ed[i].f -= t;
                Ed[i ^ 1].f += t;
                sum += t;
                if(sum == mF)
                    break;
            }
        }
    return sum;
}

int Dinic(){
	int ans = 0;
	while(bfs())
		ans += dfs(S , INF);
	return ans;
}

void input(){
	N = read();
	M = read();
	G = read();
	T = N + M + 1;
	for(int i = 1 ; i <= N ; ++i)
		num[i] = read();
	for(int i = 1 ; i <= N ; ++i){
		int v = read();
		if(num[i]){
			addEd(S , i , v);
			addEd(i , S , 0);
		}
		else{
			addEd(i , T , v);
			addEd(T , i , 0);
		}
	}
	for(int i = 1 ; i <= M ; ++i){
		int p = read() , w = read() , k = read();
		ans += w;
		for(int j = 1 ; j <= k ; ++j){
			int q = read();
			if(p){
				addEd(i + N , q , INF);
				addEd(q , i + N , 0);
			}
			else{
				addEd(q , i + N , INF);
				addEd(i + N , q , 0);
			}
		}
		int t = read();
		if(p){
			addEd(S , i + N , w + t * G);
			addEd(i + N , S , 0);
		}
		else{
			addEd(i + N , T , w + t * G);
			addEd(T , i + N , 0);
		}
	}
}

void work(){
    while(bfs())
		ans -= dfs(S , INF);
	cout << ans;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in" , "r" , stdin);
	//freopen("out" , "w" , stdout);
#endif
	input();
	work();
	return 0;
}