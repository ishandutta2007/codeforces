#include<bits/stdc++.h>
//This code is written by Itst
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

const int MAXN = 1e6 + 7;
int N , cntEd , head[MAXN] , dep[MAXN] , fa[MAXN];
struct Edge{
    int end , upEd;
}Ed[MAXN << 1];
struct cmp{
	bool operator ()(int a , int b){
		return dep[a] < dep[b];
	}
};
priority_queue < int , vector < int > , cmp > q;
bool vis[MAXN];

inline void addEd(int a , int b){
    Ed[++cntEd].end = b;
    Ed[cntEd].upEd = head[a];
    head[a] = cntEd;
} 

void dfs(int x , int p){
    dep[x] = dep[p] + 1;
    fa[x] = p;
    q.push(x);
    for(int i = head[x] ; i ; i = Ed[i].upEd)
    	if(Ed[i].end != p)
    		dfs(Ed[i].end , x);
}

void tz(int x){
	x = fa[x];
	vis[x] = 1;
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		vis[Ed[i].end] = 1;
}

int main(){
    #ifndef ONLINE_JUDGE
    //freopen("in" , "r" , stdin);
    //freopen("out" , "w" , stdout);
    #endif
    N = read();
    for(int i = 1 ; i < N ; ++i){
    	int a = read() , b = read();
    	addEd(a , b);
    	addEd(b , a);
	}
	dfs(1 , 0);
	int cnt = 0;
	while(!q.empty()){
		int t = q.top();
		q.pop();
		if(dep[t] <= 3)
			break;
		if(!vis[t]){
			++cnt;
			tz(t);
		}
	}
	cout << cnt;
    return 0;
}