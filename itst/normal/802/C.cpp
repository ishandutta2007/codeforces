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
#define INF 0x3f3f3f3f
//This code is written by Itst
using namespace std;

const int MAXN = 1e3 + 7 , MAXM = 1e6 + 7;
struct Edge{
    int end , upEd , f , c;
}Ed[MAXM];
int head[MAXN] , book[81] , pri[81];
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

bool vis[MAXN];
int dis[MAXN] , pre[MAXN] , flo[MAXN];;

inline bool SPFA(){
    memset(dis , 0x3f , sizeof(dis));
    dis[S] = 0;
    while(!q.empty())
        q.pop();
    q.push(S);
    flo[S] = INF;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        vis[t] = 0;
        for(int i = head[t] ; i ; i = Ed[i].upEd)
            if(Ed[i].f && dis[Ed[i].end] > dis[t] + Ed[i].c){
                dis[Ed[i].end] = dis[t] + Ed[i].c;
                flo[Ed[i].end] = min(Ed[i].f , flo[t]);
                pre[Ed[i].end] = i;
                if(!vis[Ed[i].end]){
                    vis[Ed[i].end] = 1;
                    q.push(Ed[i].end);
                }
            }
    }
    return dis[T] != dis[T + 1];
}

int EK(){
	int ans = 0;
    while(SPFA()){
        int cur = T , sum = 0;
        while(cur != S){
            sum += Ed[pre[cur]].c;
            Ed[pre[cur]].f -= flo[T];
            Ed[pre[cur] ^ 1].f += flo[T];
            cur = Ed[pre[cur] ^ 1].end;
        }
        ans += sum * flo[T];
    }
	return ans;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in" , "r" , stdin);
	//freopen("out" , "w" , stdout);
#endif
	cin >> N >> M;
	T = 2 * N + 2;
	addE(S , T - 1 , M);
	for(int i = 1 ; i <= N ; ++i) cin >> book[i];
	for(int i = 1 ; i <= N ; ++i) cin >> pri[i];
	for(int i = 1 ; i <= N ; ++i){
		addE(T - 1 , i , 1 , pri[book[i]]);
		addE(i , T , 1);
		addE(S , i + N , 1);
		for(int j = 1 ; j < i ; ++j)
			addE(j + N , i , 1 , book[j] == book[i] ? 0 : pri[book[i]]);
	}
	cout << EK();
	return 0;
}