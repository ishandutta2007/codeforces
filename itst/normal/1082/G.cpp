#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cctype>
#include<algorithm>
#include<cstring>
#include<iomanip>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<vector>
#include<cmath>
#define INF 0x3f3f3f3f
#define int long long
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

const int MAXN = 1e5 + 7 , MAXM = 1e6 + 7;
struct Edge{
    int end , upEd , f , c;
}Ed[MAXM];
int head[MAXN];
int N , M , S , T , cntEd = 1;
queue < int > q;

inline void addEd(int a , int b , int c , int d = 0){
    Ed[++cntEd].end = b;
    Ed[cntEd].upEd = head[a];
    Ed[cntEd].f = c;
    Ed[cntEd].c = d;
    head[a] = cntEd;
}

int cur[MAXN] , dep[MAXN];

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

signed main(){
#ifndef ONLINE_JUDGE
	freopen("in" , "r" , stdin);
	//freopen("out" , "w" , stdout);
#endif
	N = read();
	M = read();
	T = N + M + 1;
	int sum = 0;
	for(int i = 1 ; i <= N ; ++i){
		addEd(M + i , T , read());
		addEd(T , M + i , 0);
	}
	for(int i = 1 ; i <= M ; ++i){
		int a = read() , b = read() , c = read();
		sum += c;
		addEd(S , i , c);
		addEd(i , S , 0);
		addEd(i , b + M , INF);
		addEd(b + M , i , 0);
		addEd(i , a + M , INF);
		addEd(a + M , i , 0);
	}
	cout << sum - Dinic();
	return 0;
}