#include<bits/stdc++.h>
#define MAXN 50001
using namespace std;
inline int read(){
    int a = 0;
    char c = getchar();
    while(!isdigit(c))
        c = getchar();
    while(isdigit(c))	a += (a << 3) + a + (c ^ '0') , c = getchar();
    return a;
}
struct Edge{
    int end , upEd;
}Ed[MAXN << 1];
struct node{
    int in , wei;
    bool operator <(node a){return wei < a.wei;}
}Node[MAXN];
int head[MAXN] , size[MAXN] , cnt[MAXN];
int nowSize , N , K , minN , pos , cntEd , cntNode;
long long ans;
bool vis[MAXN];
inline int max(int a , int b){return a > b ? a : b;}

inline void addEd(int a , int b){
    Ed[++cntEd].end = b;
    Ed[cntEd].upEd = head[a];
    head[a] = cntEd;
}
inline void addNode(int a , int b){
    Node[++cntNode].in = a;
    Node[cntNode].wei = b;
}

void getSize(int k){
    nowSize++;
    vis[k] = 1;
    for(int i = head[k] ; i ; i = Ed[i].upEd)
        if(!vis[Ed[i].end])
            getSize(Ed[i].end);
    vis[k] = 0;
}

void getZX(int k){
    int maxSize = 0; 
    size[k] = vis[k] = 1;
    for(int i = head[k] ; i ; i = Ed[i].upEd)
        if(!vis[Ed[i].end]){
            getZX(Ed[i].end);
            maxSize = max(maxSize , size[Ed[i].end]);
            size[k] += size[Ed[i].end];
        }
    if(minN > (maxSize = max(maxSize , nowSize - size[k]))){
        minN = maxSize;
        pos = k;
    }
    vis[k] = 0;
}

void dfs(int k , int in , int len){
    if(len > K)	return;
    addNode(in , len);
    vis[k] = 1;
    for(int i = head[k] ; i ; i = Ed[i].upEd)
        if(!vis[Ed[i].end])
            dfs(Ed[i].end , in , len + 1);
    vis[k] = 0;
}

void solve(int dir){
    nowSize = 0;
    cntNode = 1;
    minN = N + 1;
    getSize(dir);
    getZX(dir);
    vis[pos] = 1;
    int in = 0;
    for(int i = head[pos] ; i ; i = Ed[i].upEd)
        if(!vis[Ed[i].end])
            dfs(Ed[i].end , ++in , 1);
    sort(Node + 1 , Node + cntNode + 1);
    int l = 1 , r = cntNode , p = cntNode , count = 0;
    bool f = 0;
    while(l < r){
    	if(l == 1 || Node[l].wei != Node[l - 1].wei){
        	while(r > p)
                cnt[Node[r--].in]--;
        	count = 0;
            while(l < r && Node[l].wei + Node[r].wei > K)
            	r--;
            if(l >= r)	break;
        	p = r;
        	while(l < p && Node[l].wei + Node[p].wei == K){
        	    cnt[Node[p].in]++;
        	    count++;
        	    f = 1;
            	p--;
        	}
        }
        ans += count - cnt[Node[l].in];
        if(p == l){
            cnt[Node[++p].in]--;
            count--;
        }
        l++;
    }
    for(int i = head[pos] ; i ; i = Ed[i].upEd)
        if(!vis[Ed[i].end])
            solve(Ed[i].end);
}
int main(){
    N = read();
    K = read();
    for(register int i = 1 ; i < N ; ++i){
        int a = read() , b = read();
        addEd(a , b);
        addEd(b , a);
    }
    solve(1);
    cout << ans;
    return 0;
}