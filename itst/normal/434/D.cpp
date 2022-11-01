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
#include<random>
#include<cassert>
#define int long long
#define inf 1e10
#define INF 1e13
//This code is written by Itst
using namespace std;

const int MAXN = 1e5 + 7 , MAXM = 1e6 + 7;
struct Edge{
    int end , upEd , f , c;
}Ed[MAXM];
int head[MAXN] , a[51] , b[51] , c[51] , l[51] , r[51] , ind[51][207];
int N , M , S , T , cntEd = 1;
queue < int > q;

inline void addEd(int a , int b , int c , int d = 0){
    Ed[++cntEd].end = b;
    Ed[cntEd].upEd = head[a];
    Ed[cntEd].f = c;
    Ed[cntEd].c = d;
    head[a] = cntEd;
}

inline void addE(int a , int b , int c , int d = 0 , bool f = 0){
	addEd(a , b , c , d); addEd(b , a , c * f , -d);
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

inline int calc(int tp , int x){
	return a[tp] * x * x + b[tp] * x + c[tp];
}

signed main(){
#ifndef ONLINE_JUDGE
	freopen("in" , "r" , stdin);
	//freopen("out" , "w" , stdout);
#endif
	ios::sync_with_stdio(0);
	cin >> N >> M;
	for(int i = 1 ; i <= N ; ++i) cin >> a[i] >> b[i] >> c[i];
	T = 1e5;
	int cnt = 0;
	for(int i = 1 ; i <= N ; ++i){
		cin >> l[i] >> r[i];
		for(int j = 0 ; j <= 200 ; ++j) ind[i][j] = ++cnt;
		addE(S , ind[i][0] , l[i] == -100 ? inf - calc(i , -100) : INF);
		addE(ind[i][200] , T , INF);
		for(int j = 1 ; j <= 200 ; ++j)
			addE(ind[i][j - 1] , ind[i][j] , j - 100 >= l[i] && j - 100 <= r[i] ? inf - calc(i , j - 100) : INF);
	}
	while(M--){
		int a , b , c;
		cin >> a >> b >> c;
		for(int i = max(0ll , c) ; i <= min(200ll , 200 + c) ; ++i)
			addE(ind[a][i] , ind[b][i - c] , INF);
		if(c < 0){
			addE(S , ind[b][-c - 1] , INF);
			addE(ind[a][200 + c] , T , INF);
		}
	}
	cout << (int)(N * inf - Dinic());
	return 0;
}